/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:41:20 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 17:17:05 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_message_erreur_bonus(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	free_bonus_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	fermer_window_bonus(t_game_bonus *jeux)
{
	mlx_destroy_window(jeux->mlx, jeux->win);
	free_bonus_map(jeux->map);
	exit(0);
}

void	vitesse_tom(t_game_bonus *jeux)
{
	static int	vitesse;

	vitesse++;
	if (vitesse > 10)
	{
		jeux->enemy_vitesse++;
		if (jeux->enemy_vitesse > 5)
			jeux->enemy_vitesse = 0;
		vitesse = 0;
	}
}
