/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:37:00 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/08 03:17:34 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(char c, int pid)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(300);
		i--;
	}
}

int	valid(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, RED"Invalid: ./client [PID] [Message]\n", 40);
		return (0);
	}
	else if (ft_atoi(av[1]) <= 0)
	{
		write(1, RED"Invalid: Check PID!\n", 26);
		return (0);
	}
	else
		return (1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (valid(ac, av) == 0)
		return (0);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_msg(av[2][i], pid);
		i++;
	}
	send_msg('\0', pid);
	return (0);
}
