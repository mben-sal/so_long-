/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:59:36 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/25 11:52:16 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_so_long(t_game *jeux)
{
	int i;

	i = 0;
	ft_check_rectangulaire(jeux);
	ft_check_murs(jeux);
	ft_check_les_element(jeux);
	
}

void	initVar(t_game *jeux)
{
	jeux->check_c = 0;
	jeux->check_e = 0;
	jeux->check_p = 0;
	jeux->lnmap = ft_strlen(jeux->map[0]);
	jeux->longeur_map = ft_lnmap(jeux);
}
void conver_image(t_game *jeux)
{
	int y;
	int x;
	
	jeux->image_door = mlx_xpm_file_to_image(jeux->mlx ,"./door .xpm",&x,&y);
	jeux->image_cheese = mlx_xpm_file_to_image(jeux->mlx ,"./cheese.xpm",&x,&y);
	jeux->player_1 = mlx_xpm_file_to_image(jeux->mlx ,"./Player 1.xpm",&x,&y);
	jeux->player_2 = mlx_xpm_file_to_image(jeux->mlx ,"./Player 2.xpm",&x,&y);
	jeux->player_3 = mlx_xpm_file_to_image(jeux->mlx ,"./Player 3.xpm",&x,&y);
	jeux->player_4 = mlx_xpm_file_to_image(jeux->mlx ,"./Player 4.xpm",&x,&y);
	jeux->the_lawn = mlx_xpm_file_to_image(jeux->mlx ,"./the lawn.xpm",&x,&y);
	jeux->the_wall = mlx_xpm_file_to_image(jeux->mlx ,"./the wall .xpm",&x,&y);
}

void remplir_map(t_game *jeux)
{
	int y_map;
	int x_map;
	int len;
	int i;
	int j;

	len = jeux->lnmap;
	y_map = 0;
	i = 0;

	while (i < jeux->longeur_map)
	{
		j = 0;
		x_map = 0;
		while(j > jeux->lnmap)
		{
			if(jeux->map[i][j] == '1')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->the_wall ,jeux->x,jeux->y);
			if(jeux->map[i][j] == '0')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->the_lawn ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'P')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player_1 ,jeux->x,jeux->y);
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player_2 ,jeux->x,jeux->y);
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player_3 ,jeux->x,jeux->y);
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->player_4 ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'C')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->image_cheese ,jeux->x,jeux->y);
			if(jeux->map[i][j] == 'E')
				mlx_put_image_to_window(jeux->mlx,jeux->win,jeux->image_door ,jeux->x,jeux->y);
			j++;
			x_map += 60;
		}
		x_map = 0;
		y_map += 70;
	}
}
int main(int ac , char **av)
{
	t_game jeux;
	int x;
	int y;
	
	if (ac != 2)
		ft_message_erreur(1);
	ft_check_map(av[1]);
	ft_validation_map(av[1] , &jeux);
	initVar(&jeux);
	ft_so_long(&jeux);
	jeux.mlx = mlx_init();
	x = jeux.lnmap  * 60;
	y = jeux.longeur_map * 70;
	jeux.win = mlx_new_window(jeux.mlx, x, y, "so_long");
	conver_image(&jeux);
	remplir_map(&jeux);
	// jeux.img = mlx_new_image(jeux.mlx, 2, 1);
	
	mlx_loop(jeux.mlx);
	// int i;
	// i = 0;
	// while(jeux.map[i])
	// {
	// 	printf("%s\n" , jeux.map[i]);
	// 	i++;
	// }
}
	
