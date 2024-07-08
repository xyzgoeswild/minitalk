CC         = cc
CFLAGS     = -Wall -Wextra -Werror

CLIENT_SRC = client.c mini_assist.c
SERVER_SRC = server.c mini_assist.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT     = client
SERVER     = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER)

clean:
	rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
