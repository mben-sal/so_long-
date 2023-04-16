/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_jerry_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:04:08 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 22:06:23 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_gauche_bonus(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y][jeux->x - 1] == '1')
		return ;
	if (jeux->map[jeux->y][jeux->x - 1] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y][jeux->x - 1] = 'P';
		jeux->check_c--;
	}
	if (jeux->map[jeux->y][jeux->x - 1] == 'E')
	{
		if (jeux->check_c != 0)
			return ;
		if (jeux->check_c == 0)
		{
			jeux->count++;
			exit(0);
		}
	}
	ft_check_enemy_gauche(jeux);
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y][jeux->x - 1] = 'P';
	jeux->count++;
	mlx_clear_window(jeux->mlx, jeux->win);
	remplir_map_bonus(jeux);
}

void	ft_droit_bonus(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y][jeux->x + 1] == '1')
		return ;
	if (jeux->map[jeux->y][jeux->x + 1] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y][jeux->x + 1] = 'P';
		jeux->check_c--;
	}
	if (jeux->map[jeux->y][jeux->x +1] == 'E')
	{
		if (jeux->check_c != 0)
			return ;
		if (jeux->check_c == 0)
		{
			jeux->count++;
			exit(0);
		}
	}
	ft_check_enemy_droit(jeux);
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y][jeux->x + 1] = 'P';
	jeux->count++;
	mlx_clear_window(jeux->mlx, jeux->win);
	remplir_map_bonus(jeux);
}

void	ft_bas_bonus(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y + 1][jeux->x] == '1')
		return ;
	if (jeux->map[jeux->y + 1][jeux->x] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y + 1][jeux->x] = 'P';
		jeux->check_c--;
	}
	if (jeux->map[jeux->y + 1][jeux->x] == 'E')
	{
		if (jeux->check_c != 0)
			return ;
		if (jeux->check_c == 0)
		{
			jeux->count++;
			exit(0);
		}
	}
	ft_check_enemy_bas(jeux);
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y + 1][jeux->x] = 'P';
	jeux->count++;
	mlx_clear_window(jeux->mlx, jeux->win);
	remplir_map_bonus(jeux);
}

void	ft_haut_bonus(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y - 1][jeux->x] == '1')
		return ;
	if (jeux->map[jeux->y - 1][jeux->x] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y - 1][jeux->x] = 'P';
		jeux->check_c--;
	}
	if (jeux->map[jeux->y - 1][jeux->x] == 'E')
	{
		if (jeux->check_c != 0)
			return ;
		if (jeux->check_c == 0)
		{
			jeux->count++;
			exit(0);
		}
	}
	ft_check_enemy_haut(jeux);
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y - 1][jeux->x] = 'P';
	jeux->count++;
	mlx_clear_window(jeux->mlx, jeux->win);
	remplir_map_bonus(jeux);
}

void	cherche_player_bonus(t_game_bonus *jeux)
{
	int	i;
	int	j;

	i = 0;
	while (jeux->map[i])
	{
		j = 0;
		while (jeux->map[i][j])
		{
			if (jeux->map[i][j] == 'P')
			{
				jeux->y = i;
				jeux->x = j;
			}
			j++;
		}
		i++;
	}
}
