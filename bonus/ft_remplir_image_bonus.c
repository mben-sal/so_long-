/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remplir_image_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:55:15 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/10 00:32:35 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long_bonus.h"

void	moveMouse_bonus(t_game_bonus *jeux)
{
	// char **mouse;

	mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player[jeux->m] ,jeux->x,jeux->y);
	jeux->m++;
	if (jeux->m == 3)
		jeux->m= 0;
}

void	moveTome_bonus(t_game_bonus *jeux)
{
	// char **mouse;
	static int i;
	i = 0;
	jeux->n = 0;
	mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->tom[jeux->n] ,jeux->x,jeux->y);
	
	if( i > 10)
	{
		i++;
		if(jeux->n < 6)
		{
			mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->tom[jeux->n] ,jeux->x,jeux->y);
			jeux->n++;
		}
		else
			jeux->n = 0;
		i = 0;
	}
}
void remplir_map_bonus(t_game_bonus *jeux)
{
	int len;
	int i;
	int j;

	len = jeux->lnmap;
	jeux->y = 0;
	i = 0;
	while (jeux->map[i])
	{
		j = 0;
		jeux->x = 0;
		while(jeux->map[i][j])
		{
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->the_lawn ,jeux->x,jeux->y);
			if(jeux->map[i][j] == '1')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->the_wall ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'P')
				moveMouse_bonus(jeux);
				// mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player_1, jeux->x,jeux->y);
			if(jeux->map[i][j] == 'C')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->image_cheese ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'E')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->image_door ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'N')
				moveTome_bonus(jeux);
			j++;
			jeux->x += 60;
		}
		jeux->x = 0;
		jeux->y += 70;
		i++;
	}
}

void conver_image_bonus(t_game_bonus *jeux)
{
	int y;
	int x;
	
	jeux->image_door = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/door .xpm",&x,&y);
	if (!jeux->image_door)
		exit(1);
	jeux->image_cheese = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/cheese.xpm",&x,&y);
	if (!jeux->image_cheese)
		exit(1);
	jeux->the_lawn = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/the lawn.xpm",&x,&y);
	if (!jeux->the_lawn)
		exit(1);
	jeux->the_wall = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/the wall .xpm",&x,&y);
	if (!jeux->the_wall)
		exit(1);
	jeux->player[0] = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/mouse1.xpm",&x,&y);
	if (!jeux->player[0])
		exit(1);
	jeux->player[1] = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/mouse2.xpm",&x,&y);
	if (!jeux->player[1])
		exit(1);
	jeux->player[2] = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/mouse3.xpm",&x,&y);
	if (!jeux->player[2])
		exit(1);
	jeux->player[3] = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/mouse4.xpm",&x,&y);
	if (!jeux->player[3])
		exit(1);
	jeux->tom[0] = mlx_xpm_file_to_image(jeux->mlx , "./minilibx/cat1.xpm",&x , &y);
	if (!jeux->tom[0])
		exit(1);
	jeux->tom[1] = mlx_xpm_file_to_image(jeux->mlx , "./minilibx/cat2.xpm",&x , &y);
	if (!jeux->tom[1])
		exit(1);
	jeux->tom[2] = mlx_xpm_file_to_image(jeux->mlx , "./minilibx/cat3.xpm",&x , &y);
	if (!jeux->tom[2])
		exit(1);
	jeux->tom[3] = mlx_xpm_file_to_image(jeux->mlx , "./minilibx/cat4.xpm",&x , &y);
	if (!jeux->tom[3])
		exit(1);
	jeux->tom[4] = mlx_xpm_file_to_image(jeux->mlx , "./minilibx/cat5.xpm",&x , &y);
	if (!jeux->tom[4])
		exit(1);
	jeux->tom[5] = mlx_xpm_file_to_image(jeux->mlx , "./minilibx/cat6.xpm",&x , &y);
	if (!jeux->tom[5])
		exit(1);
}