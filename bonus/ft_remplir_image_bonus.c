/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remplir_image_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:55:15 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 17:13:14 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	vitesse_mouse_bonus(t_game_bonus *jeux)
{
	static int	vitesse;

	vitesse++;
	if (vitesse > 10)
	{
		jeux->mouse_vitesse++;
		if (jeux->mouse_vitesse > 3)
			jeux->mouse_vitesse = 0;
		vitesse = 0;
	}
}

void	movemouse_bonus(t_game_bonus *jeux)
{
	mlx_put_image_to_window(jeux->mlx, jeux->win,
		jeux->player[jeux->mouse_vitesse], jeux->x, jeux->y);
	jeux->m++;
	if (jeux->m == 3)
		jeux->m = 0;
}

void	movetom_bonus(t_game_bonus *jeux)
{
	mlx_put_image_to_window(jeux->mlx, jeux->win,
		jeux->tom[jeux->enemy_vitesse], jeux->x, jeux->y);
	jeux->n++;
	if (jeux->n == 5)
		jeux->n = 0;
}

void	movetome_bonus(t_game_bonus *jeux)
{
	int	i;
	int	j;

	jeux->y = 0;
	i = 0;
	while (jeux->map[i])
	{
		j = 0;
		jeux->x = 0;
		while (jeux->map[i][j])
		{
			if (jeux->map[i][j] == 'N')
				movetom_bonus(jeux);
			j++;
			jeux->x += 60;
		}
		jeux->x = 0;
		jeux->y += 70;
		i++;
	}
}

void	enemy_tom(t_game_bonus *jeux)
{
	static int		position;
	int				i;
	int				j;

	i = -1;
	if (position++ == 50)
	{
		while (++i < jeux->longeur_map)
		{
			j = -1;
			while (++j < ft_strlen(jeux->map[i]))
				move_tom(jeux, i, j);
		}
		position = 0;
	}
}
