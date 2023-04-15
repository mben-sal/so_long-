/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_chemin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:39:38 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 14:45:16 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_chemin(t_game *jeux, int y, int x, char point)
{
	if (jeux->map2[y][x] == '1' || jeux->map2[y][x] == 'X')
		return (0);
	if (jeux->map2[y][x] == point)
		return (1);
	jeux->map2[y][x] = 'X';
	if (ft_check_chemin(jeux, y + 1, x, point) == 1)
		return (1);
	if (ft_check_chemin(jeux, y - 1, x, point) == 1)
		return (1);
	if (ft_check_chemin(jeux, y, x + 1, point) == 1)
		return (1);
	if (ft_check_chemin(jeux, y, x - 1, point) == 1)
		return (1);
	return (0);
}

void	ft_retour_map(t_game *jeux)
{
	int	i;
	int	j;

	i = 0 ;
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

void	ft_chemin_for_cheese(t_game *jeux)
{
	int	i;
	int	j;

	i = 0;
	while (i < jeux->longeur_map)
	{
		j = 0;
		while (j < jeux->lnmap)
		{
			if (jeux->map2[i][j] == 'C')
			{
				if (!ft_check_chemin(jeux, i, j, 'E'))
				{
					ft_message_erreur("le joueur ne trouve pas aucun chemin\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	copier_map(t_game *jeux)
{
	int	i;

	i = 0;
	jeux->map2 = malloc(sizeof(char *) * (jeux->longeur_map));
	if (!jeux->map2)
		return ;
	while (i < jeux->longeur_map)
	{
		jeux->map2[i] = ft_strdup(jeux->map[i]);
		i++;
	}
	jeux->map2[i] = NULL;
}

void	ft_validation_chemin(t_game *jeux)
{
	cherche_player(jeux);
	if (!ft_check_chemin(jeux, jeux->y, jeux->x, 'E'))
	{
		ft_message_erreur("2 - erreur : le joueur ne trouve pas aucun chemin\n");
		exit(1);
	}
	ft_retour_map(jeux);
	ft_chemin_for_cheese(jeux);
}
