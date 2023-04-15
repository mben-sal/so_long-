/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_chemin_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:24:54 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 17:22:09 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	ft_check_chemin_bonus(t_game_bonus *jeux, int y, int x, char point )
{
	if (jeux->map2[y][x] == '1' || jeux->map2[y][x] == 'X')
		return(0);
	if (jeux->map2[y][x] == point)
		return(1);
	jeux->map2[y][x] = 'X';
	if (ft_check_chemin_bonus(jeux, y + 1, x, point) == 1)
		return(1);
	if (ft_check_chemin_bonus(jeux, y - 1 , x, point) == 1)
		return(1);
	if (ft_check_chemin_bonus(jeux, y , x + 1, point) == 1)
		return(1);
	if (ft_check_chemin_bonus(jeux, y, x - 1, point) == 1)
		return(1);
	return(0);
}

void	ft_retour_map_bonus(t_game_bonus *jeux)
{
	int	i;
	int	j;
	
	i = 0;
	while (jeux->map[i])
	{
		j = 0;
		while (jeux->map2[i][j])
		{
			if (jeux->map2[i][j] == 'X')
			{
				jeux->map2[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	ft_chemin_for_cheese_bonus(t_game_bonus *jeux)
{
	int i;
	int j;
	
	i = 0;
	while (i < jeux->longeur_map)
	{
		j = 0;
		while (j < jeux->lnmap)
		{
			if (jeux->map2[i][j] == 'C')
			{
				if (!ft_check_chemin_bonus(jeux, i, j, 'E'))
				{
					ft_message_erreur_bonus("le joueur ne trouve pas aucun chemin\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	copier_map_bonus(t_game_bonus *jeux)
{
	int i;

	i = 0;
	jeux->map2 = malloc(sizeof(char*)*(jeux->longeur_map));
	if (!jeux->map2)
		return ;
	while ( i < jeux->longeur_map)
	{
		jeux->map2[i] = ft_strdup(jeux->map[i]);
		i++;
	}
	jeux->map2[i] = NULL;
}

void ft_validation_chemin_bonus(t_game_bonus *jeux)
{
	cherche_player_bonus(jeux);
	if (!ft_check_chemin_bonus(jeux , jeux->y, jeux->x , 'E'))
	{
		ft_message_erreur_bonus("le joueur ne trouve pas aucun chemin\n");
		exit(1);
	}
	ft_retour_map_bonus(jeux);
	ft_chemin_for_cheese_bonus(jeux);
}