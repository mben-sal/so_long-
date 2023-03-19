# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 19:42:40 by mben-sal          #+#    #+#              #
#    Updated: 2023/03/19 19:48:54 by mben-sal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

SRC = 	./so_long.c\
		./ft_message_erreur.c\
		./git_next_ligne/get_next_line_utils.c\
		./git_next_ligne/get_next_line.c\
		./utils/ft_split.c\
		./utils/ft_strncmp.c\
		./utils/ft_putstr.c\
		./ft_check_validation_map.c\
		./ft_check_murs.c\
		./ft_check_element.c 
		

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc


all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all