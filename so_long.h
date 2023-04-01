/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:11:03 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/01 12:56:35 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<stdarg.h>
# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<string.h>
# include <sys/errno.h>
# include <errno.h>
#include <mlx.h>

typedef struct s_spl
{
	int		i;
	int		j;
	int		len;
	int		index;
	int		count;
	char	**ptr;
}	t_spl;

typedef struct s_game 
{
	int		check_e;
	int		check_c;
	int 	check_p;
	int		len_map;
	int 	lnmap;
	int		longeur_map;
	void	*img;
	void	*mlx;
	void	*win;
	char	**map;
	int 	count_c;
	void *image_door;
	void *image_cheese;
	void *player_1;
	void *player_2;
	void *player_3;
	void *player_4;
	void *the_lawn;
	void *the_wall;
	int x;
	int y;
}	t_game;

void ft_message_erreur(int ac);
int 	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int  len);
char	*get_next_line(int fd);
char	*ft_save(char **str);
char	*ft_read(int fd, char*save, char*buff);
void	ft_free(char **dst, char *src, char *to_free);
int	ft_line(char *s);
int	ft_strncmp(char *first, char *second);
char	**ft_split(char *s, char c);
void	ft_putstr(char *s);
void ft_check_map(char *map);
void ft_validation_map(char *av , t_game *jeux);
void ft_check_murs(t_game *jeux);
void ft_murs(t_game *jeux);
void ft_check_rectangulaire(t_game *jeux);
void ft_check(t_game *jeux);
void ft_check_les_element(t_game *jeux);
int ft_lnmap(t_game *jeux);
void ft_gauche(t_game *jeux);
void ft_droit(t_game *jeux);
void ft_bas(t_game *jeux);
void ft_haut(t_game *jeux);
void remplir_map(t_game *jeux);
void cherche_player(t_game *jeux);
void conver_image(t_game *jeux);
# endif