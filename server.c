/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:37:02 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/06/28 23:35:17 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void    handler(int sig)
{
    static unsigned char c;
    static int  i;

    if (sig == SIGUSR1)
        c = c | (1<<i);
    else if (sig == SIGUSR2)
        c = c | (0<<i);
    i++;
    if (i == 8)
    {
        if (c == '\0')
        {
            ft_putchar_fd('\n', 1);
            c = 0;
            i = 0;
        }
        else
        {
            ft_putchar_fd(c, 1);
            c = 0;
            i = 0;
        }
    }
}

void    h_sigint()
{
    write(1, RED"\nProcess Terminated [2]!\n", 31);
    exit(0);
}

int main(int ac, char **av)
{
    (void) **av;
    if (ac != 1)
        return (0);

    write(1, GREEN"Server PID: ", 18);
    ft_putnbr_fd(getpid(), 1);
    write(1, YELLOW"\nAwaiting Message...\n", 27);
    write(1, RESET, 4);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    signal(SIGINT, h_sigint);
    while (1) {
        ;
    }
    return (0);
}
