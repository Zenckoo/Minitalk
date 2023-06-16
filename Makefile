# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 14:29:29 by isitbon           #+#    #+#              #
#    Updated: 2023/06/07 19:27:57 by isitbon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFTPRINTF_PATH = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(SERVER_OBJ) $(CLIENT_OBJ)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) -o server $(SERVER_OBJ) $(LIBFTPRINTF_PATH)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJ) $(LIBFTPRINTF_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ft_printf clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re