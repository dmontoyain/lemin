#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 20:24:48 by dmontoya          #+#    #+#              #
#    Updated: 2018/03/06 22:32:19 by dmontoya         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

FUNCTIONS =		main \
				dijkstra \
				lemin_utilities \
				add_room_link \
				parse \
				error \
				mapvalidation_tools

LIB = libft/
PRINTF = printf/
LIBS = $(LIB)libft.a $(PRINTF)libftprintf.a

C_FILES = $(addprefix ./srcs/, $(addsuffix .c, $(FUNCTIONS)))
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):

	$(MAKE) -C $(LIB)
	$(MAKE) -C $(PRINTF)
	$(CC) $(FLAGS) $(C_FILES) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJ_FILES)
	rm -rf ./srcs/*~
	$(MAKE) clean -C $(LIB)
	$(MAKE) clean -C $(PRINTF)


fclean:	clean
	$(MAKE) fclean -C $(LIB)
	$(MAKE) fclean -C $(PRINTF)
	rm -rf $(NAME)

re: fclean all
