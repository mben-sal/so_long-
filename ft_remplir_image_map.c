/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remplir_image_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:48:31 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/01 13:58:47 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void remplir_map(t_game *jeux)
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
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player_4 ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'C')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->image_cheese ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'E')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->image_door ,jeux->x,jeux->y);
			j++;
			jeux->x += 60;
		}
		jeux->x = 0;
		jeux->y += 70;
		i++;
	}
}

void conver_image(t_game *jeux)
{
	int y;
	int x;
	
	jeux->image_door = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/door .xpm",&x,&y);
	jeux->image_cheese = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/cheese.xpm",&x,&y);
	jeux->player_1 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 1.xpm",&x,&y);
	jeux->player_2 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 2.xpm",&x,&y);
	jeux->player_3 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 3.xpm",&x,&y);
	jeux->player_4 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 4 .xpm",&x,&y);
	jeux->the_lawn = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/the lawn.xpm",&x,&y);
	jeux->the_wall = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/the wall .xpm",&x,&y);
}