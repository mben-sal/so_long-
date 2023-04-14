/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:32:38 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/13 23:48:59 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
#include <stdbool.h>


typedef struct s_spl
{
	int		i;
	int		j;
	int		len;
	int		index;
	int		count;
	char	**ptr;
}	t_spl;

typedef struct s_game_bonus
{
	int		check_e;
	int 	check_c;
	int 	check_p;
	int		len_map;
	int 	lnmap;
	int		longeur_map;
	void	*img;
	void	*mlx;
	void	*win;
	char	**map;
	char **map2;
	int 	count_c;
	void *image_door;
	void *image_cheese;
	void *player_1;
	void *player_2;
	void *player_3;
	void *player_4;
	void *player[4];
	void *the_lawn;
	void *the_wall;
	int x;
	int y;
	int m;
	int n;
	int count;
	void *tom[6];
	int	enemy_vitesse;
	int mouse_vitesse;
}	t_game_bonus;


void ft_message_erreur_bonus(char *str);
void ft_check_map_bonus(char *map);
void ft_validation_map_bonus(char *av , t_game_bonus *jeux);
void	initVar_bonus(t_game_bonus *jeux);
void ft_so_long_bonus(t_game_bonus *jeux);
void conver_image_bonus(t_game_bonus *jeux);
void remplir_map_bonus(t_game_bonus *jeux);
void	moveMouse_bonus(t_game_bonus *jeux);
int	key_hook_bonus(int keycode, t_game_bonus *jeux);
void cherche_player_bonus(t_game_bonus *jeux);
void ft_haut_bonus(t_game_bonus *jeux);
void ft_bas_bonus(t_game_bonus *jeux);
void ft_droit_bonus(t_game_bonus *jeux);
void ft_gauche_bonus(t_game_bonus *jeux);
int ft_lnmap_bonus(t_game_bonus *jeux);
void ft_check_les_element(t_game_bonus *jeux);
void ft_check_les_element_bonus(t_game_bonus *jeux);
void ft_check_bonus (t_game_bonus *jeux);
void ft_check_rectangulaire_bonus (t_game_bonus *jeux);
void ft_check_murs_bonus(t_game_bonus *jeux);
void ft_murs_bonus(t_game_bonus *jeux);
int	ft_check_chemin_bonus(t_game_bonus *jeux, int y, int x, char point );
void ft_chemin_for_cheese_bonus(t_game_bonus *jeux);
void	copier_map_bonus(t_game_bonus *jeux);
void ft_validation_chemin_bonus(t_game_bonus *jeux);
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
void	moveMouse_bonus(t_game_bonus *jeux);
void ft_so_long_bonus(t_game_bonus *jeux);
void	moveTome_bonus(t_game_bonus *jeux);
void ft_move_tom_gauche(t_game_bonus *jeux, int i , int j);
void ft_move_tom_droit(t_game_bonus *jeux, int i , int j);
void ft_move_tom_haut(t_game_bonus *jeux, int i , int j);
void ft_move_tom_bas(t_game_bonus *jeux, int i , int j);
void    enemy_tom(t_game_bonus *jeux);
void    move_tom(t_game_bonus *map, int i, int j);
char	*ft_itoa(int n);
void    vitesse_tom(t_game_bonus *jeux);
void	vitesse_mouse(t_game_bonus *jeux);
# endif

