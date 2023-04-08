/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_jerry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:23:32 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/08 23:38:02 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_gauche(t_game *jeux)
{
	if(jeux->map[jeux->y][jeux->x - 1] == '1')
		return;
	if(jeux->map[jeux->y][jeux->x - 1] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y][jeux->x - 1] = 'P';
		jeux->check_c--;
	}
	if(jeux->map[jeux->y ][jeux->x - 1] == 'E')
	{
		if(jeux->check_c != 0)
			return;
		if(jeux->check_c == 0)
			exit(0);
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y][jeux->x - 1] = 'P';
	jeux->count++;
	printf("%d\n" , jeux->count);
	mlx_clear_window(jeux->mlx , jeux->win);
	remplir_map(jeux);
}

void ft_droit(t_game *jeux)
{
	if(jeux->map[jeux->y][jeux->x + 1] == '1')
		return;
	if(jeux->map[jeux->y][jeux->x + 1] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y][jeux->x + 1] = 'P';
		jeux->check_c--;
	}
	if(jeux->map[jeux->y ][jeux->x +1 ] == 'E')
	{
		if(jeux->check_c != 0)
			return;
		if(jeux->check_c == 0)
			exit(0);
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y][jeux->x + 1] = 'P';
	jeux->count++;
	printf("%d\n" , jeux->count);
	mlx_clear_window(jeux->mlx , jeux->win);
	remplir_map(jeux);
}

void ft_bas(t_game *jeux)
{
	if(jeux->map[jeux->y + 1][jeux->x ] == '1')
		return;
	if(jeux->map[jeux->y + 1][jeux->x] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y + 1 ][jeux->x] = 'P';
		jeux->check_c--;
	}
	if(jeux->map[jeux->y + 1][jeux->x] == 'E')
	{
		if(jeux->check_c != 0)
			return;
		if(jeux->check_c == 0)
			exit(0);
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y + 1][jeux->x] = 'P';
	jeux->count++;
	printf("%d\n" , jeux->count);
	mlx_clear_window(jeux->mlx , jeux->win);
	remplir_map(jeux);
}

void ft_haut(t_game *jeux)
{
	if(jeux->map[jeux->y - 1][jeux->x] == '1')
		return;
	if(jeux->map[jeux->y - 1][jeux->x] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y - 1][jeux->x ] = 'P';
		jeux->check_c--;
	}
	if(jeux->map[jeux->y - 1][jeux->x] == 'E')
	{
		if(jeux->check_c != 0)
			return;
		if(jeux->check_c == 0)
			exit(0);
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y - 1][jeux->x] = 'P';
	jeux->count++;
	printf("%d\n" , jeux->count);
	mlx_clear_window(jeux->mlx , jeux->win);
	remplir_map(jeux);
}

void cherche_player(t_game *jeux)
{
	int i;
	int j;
	
	i = 0;
	while(jeux->map[i])
	{
		j = 0;
		while(jeux->map[i][j])
		{
			if(jeux->map[i][j] == 'P')
			{
				jeux->y = i;
				jeux->x = j;
			}
			j++;
		}
		i++;
	}
}