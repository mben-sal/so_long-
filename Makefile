# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 19:42:40 by mben-sal          #+#    #+#              #
#    Updated: 2023/04/16 21:58:40 by mben-sal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./mandatory/so_long
NAME_B = ./bonus/so_long_bonus

HEADER = ./mandatory/so_long.h
HEADER_B = ./bonus/so_long_bonus.h

SRC = 	./mandatory/so_long.c\
		./git_next_ligne/get_next_line_utils.c\
		./git_next_ligne/get_next_line.c\
		./utils/ft_split.c\
		./utils/ft_strncmp.c\
		./utils/ft_putstr.c\
		./utils/ft_putnbr.c\
		./mandatory/ft_check_validation_map.c\
		./mandatory/ft_check_murs.c\
		./mandatory/ft_check_element.c\
		./mandatory/ft_move_jerry.c\
		./mandatory/ft_validation_chemin.c\
		./mandatory/ft_message_erreur.c\
		./mandatory/ft_remplir_image_map.c
		
SRC_B = ./bonus/ft_check_element_bonus.c\
		./bonus/ft_check_murs_bonus.c\
		./bonus/ft_check_validation_map_bonus.c\
		./bonus/ft_message_bonus.c\
		./bonus/ft_remplir_image_bonus.c\
		./bonus/ft_validation_chemin_bonus.c\
		./bonus/move_jerry_bonus.c\
		./bonus/so_long_bonus.c\
		./bonus/ft_move_tom.c\
		./bonus/windows_image.c\
		./bonus/ft_check_enemy.c\
		./git_next_ligne/get_next_line_utils.c\
		./git_next_ligne/get_next_line.c\
		./utils/ft_split.c\
		./utils/ft_strncmp.c\
		./utils/ft_itoa.c\
		./utils/ft_putstr.c
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc


all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
$(NAME_B) : $(OBJ_B) $(HEADER_B)
			$(CC) $(CFLAGS) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
clean:
		rm -rf $(OBJ) $(OBJ_B)

fclean: clean
		rm -rf $(NAME) $(NAME_B)

re:	fclean all bonus