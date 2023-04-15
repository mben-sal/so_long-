/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:50:30 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 17:13:13 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_window(t_game_bonus *jeux, int i, int j)
{
	mlx_put_image_to_window(jeux->mlx, jeux->win,
		jeux->the_lawn, jeux->x, jeux->y);
	if (jeux->map[i][j] == '1')
		mlx_put_image_to_window(jeux->mlx, jeux->win,
			jeux->the_wall, jeux->x, jeux->y);
	if (jeux->map[i][j] == 'P')
		movemouse_bonus(jeux);
	if (jeux->map[i][j] == 'C')
		mlx_put_image_to_window(jeux->mlx, jeux->win,
			jeux->image_cheese, jeux->x, jeux->y);
	if (jeux->map[i][j] == 'E')
		mlx_put_image_to_window(jeux->mlx, jeux->win,
			jeux->image_door, jeux->x, jeux->y);
}

void	remplir_map_bonus(t_game_bonus *jeux)
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
			ft_window(jeux, i, j);
			jeux->x += 60;
		}
		jeux->x = 0;
		jeux->y += 70;
	}
	movetome_bonus(jeux);
}

void	ft_image_enemy(t_game_bonus *jeux, int x, int y)
{
	jeux->tom[0] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/tom1.xpm", &x, &y);
	if (!jeux->tom[0])
		exit(1);
	jeux->tom[1] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/tom2.xpm", &x, &y);
	if (!jeux->tom[1])
		exit(1);
	jeux->tom[2] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/tom3.xpm", &x, &y);
	if (!jeux->tom[2])
		exit(1);
	jeux->tom[3] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/tom4.xpm", &x, &y);
	if (!jeux->tom[3])
		exit(1);
	jeux->tom[4] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/tom5.xpm", &x, &y);
	if (!jeux->tom[4])
		exit(1);
	jeux->tom[5] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/tom6.xpm", &x, &y);
	if (!jeux->tom[5])
		exit(1);
}

void	ft_image_player(t_game_bonus *jeux, int x, int y)
{
	jeux->player[0] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/mouse1.xpm", &x, &y);
	if (!jeux->player[0])
		exit(1);
	jeux->player[1] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/mouse2.xpm", &x, &y);
	if (!jeux->player[1])
		exit(1);
	jeux->player[2] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/mouse3.xpm", &x, &y);
	if (!jeux->player[2])
		exit(1);
	jeux->player[3] = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/mouse4.xpm", &x, &y);
	if (!jeux->player[3])
		exit(1);
}

void	conver_image_bonus(t_game_bonus *jeux)
{
	int	y;
	int	x;

	jeux->image_door = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/door .xpm", &x, &y);
	if (!jeux->image_door)
		exit(1);
	jeux->image_cheese = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/cheese.xpm", &x, &y);
	if (!jeux->image_cheese)
		exit(1);
	jeux->the_lawn = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/the lawn.xpm", &x, &y);
	if (!jeux->the_lawn)
		exit(1);
	jeux->the_wall = mlx_xpm_file_to_image(jeux->mlx,
			"./minilibx/the wall .xpm", &x, &y);
	if (!jeux->the_wall)
		exit(1);
	ft_image_player(jeux, x, y);
	ft_image_enemy(jeux, x, y);
}
