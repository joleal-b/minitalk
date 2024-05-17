# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joleal-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 12:20:27 by joleal-b          #+#    #+#              #
#    Updated: 2024/05/15 09:26:46 by joleal-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libprintf.a

SRC= ft_putnbr.c ft_putptr.c ft_putstr.c ft_putchar.c ft_puthexa.c \
	 ft_putunbr.c ft_printf.c \

CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
AR=ar rcs

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
				@$(AR) $(NAME) $(OBJ)

clean:
				@$(RM) $(OBJ) 

fclean: clean
				@$(RM) $(NAME)

re: fclean all
