/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remplir_image_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:48:31 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 14:37:06 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movemouse(t_game *jeux)
{
	mlx_put_image_to_window (jeux->mlx, jeux->win,
		jeux->player[jeux->m], jeux->x, jeux->y);
	jeux->m++;
	if (jeux->m == 3)
		jeux->m = 0;
}

void	window_image(t_game *jeux, int i, int j)
{
	mlx_put_image_to_window(jeux->mlx, jeux->win,
		jeux->the_lawn, jeux->x, jeux->y);
	if (jeux->map[i][j] == '1')
		mlx_put_image_to_window (jeux->mlx, jeux->win,
			jeux->the_wall, jeux->x, jeux->y);
	if (jeux->map[i][j] == 'P')
		movemouse(jeux);
	if (jeux->map[i][j] == 'C')
		mlx_put_image_to_window (jeux->mlx, jeux->win,
			jeux->image_cheese, jeux->x, jeux->y);
	if (jeux->map[i][j] == 'E')
		mlx_put_image_to_window (jeux->mlx, jeux->win,
			jeux->image_door, jeux->x, jeux->y);
	jeux->x += 60;
}

void	remplir_map(t_game *jeux)
{
	int	len;
	int	i;
	int	j;

	len = jeux->lnmap;
	jeux->y = 0;
	i = -1;
	while (jeux->map[++i])
	{
		j = -1;
		jeux->x = 0;
		while (jeux->map[i][++j])
		{
			window_image(jeux, i, j);
		}
		jeux->x = 0;
		jeux->y += 70;
	}
}

void	conver_palyer(t_game *jeux)
{
	int	y;
	int	x;

	jeux->player[0] = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/mouse1.xpm", &x, &y);
	if (!jeux->player[0])
		exit(1);
	jeux->player[1] = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/mouse2.xpm", &x, &y);
	if (!jeux->player[1])
		exit(1);
	jeux->player[2] = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/mouse3.xpm", &x, &y);
	if (!jeux->player[2])
		exit(1);
	jeux->player[3] = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/mouse4.xpm", &x, &y);
	if (!jeux->player[3])
		exit(1);
}

void	conver_image(t_game *jeux)
{
	int	y;
	int	x;

	jeux->image_door = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/door .xpm", &x, &y);
	if (!jeux->image_door)
		exit(1);
	jeux->image_cheese = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/cheese.xpm", &x, &y);
	if (!jeux->image_cheese)
		exit(1);
	jeux->the_lawn = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/the lawn.xpm", &x, &y);
	if (!jeux->the_lawn)
		exit(1);
	jeux->the_wall = mlx_xpm_file_to_image (jeux->mlx,
			"./minilibx/the wall .xpm", &x, &y);
	if (!jeux->the_wall)
		exit(1);
	conver_palyer(jeux);
}
