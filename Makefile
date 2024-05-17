# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joleal-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 15:15:21 by joleal-b          #+#    #+#              #
#    Updated: 2024/05/09 17:32:57 by joleal-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= client server

FTPRINTF_DIR		= ft_printf/
FTPRINTF_NAME		= libprintf.a
FTPRINTF		= $(FTPRINTF_DIR)$(FTPRINTF_NAME)

CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

CLIENT = client
SERVER = server
UTILS = utils

SRC_C = client.c
OBJ_C = $(SRC_C:%.c=%.o)

SRC_S = server.c
OBJ_S = $(SRC_S:%.c=%.o)

SRC_U = utils.c
OBJ_U = $(SRC_U:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_S) $(OBJ_C) $(OBJ_U) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(OBJ_S) $(OBJ_U) $(FTPRINTF) -o $(SERVER)
	@$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_U) $(FTPRINTF) -o $(CLIENT)

$(FTPRINTF):
		${MAKE} -C ./ft_printf

clean:
	$(MAKE) clean -C ./ft_printf
	@$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_U)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	@$(RM) $(NAME)

re: fclean all
