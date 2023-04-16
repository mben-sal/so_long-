/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:41:20 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 00:06:27 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long_bonus.h"

void ft_message_erreur_bonus(char *str)
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