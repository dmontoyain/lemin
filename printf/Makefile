#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 20:24:48 by dmontoya          #+#    #+#              #
#    Updated: 2018/02/07 16:34:28 by dmontoya         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FUNCTIONS = ft_printf \
			types_handler \
			flags \
			types_handler_a \
			types_handler_b \
			flag_utilities \
			mod_handler \
			num_utilities \
			types_handler_d \
			widthflag \
			utilities \
			wchar_utilities

INCL = -I libftprintf.h
C_FILES = $(addsuffix .c, $(FUNCTIONS))
OBJ_FILES = $(addsuffix .o, $(FUNCTIONS))
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -g $(INCL) -c $(C_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

clean:
	@rm -rf $(OBJ_FILES)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

