/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:59:36 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/30 23:02:51 by mben-sal         ###   ########.fr       */
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
	
	jeux->image_door = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/door .xpm",&x,&y);
	jeux->image_cheese = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/cheese.xpm",&x,&y);
	jeux->player_1 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 1.xpm",&x,&y);
	jeux->player_2 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 2.xpm",&x,&y);
	jeux->player_3 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 3.xpm",&x,&y);
	jeux->player_4 = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/Player 4 .xpm",&x,&y);
	jeux->the_lawn = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/the lawn.xpm",&x,&y);
	jeux->the_wall = mlx_xpm_file_to_image(jeux->mlx ,"./minilibx/the wall .xpm",&x,&y);
}

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

void ft_gauche(t_game *jeux)
{
	if(jeux->map[jeux->y][jeux->x - 1] == '1')
		return;
	else if(jeux->map[jeux->y][jeux->x - 1] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y][jeux->x - 1] = 'P';
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y][jeux->x - 1] = 'P';
	remplir_map(jeux);
}

void ft_droit(t_game *jeux)
{
	if(jeux->map[jeux->y][jeux->x + 1] == '1')
		return;
	else if(jeux->map[jeux->y][jeux->x + 1] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y][jeux->x + 1] = 'P';
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y][jeux->x + 1] = 'P';
	remplir_map(jeux);
}

void ft_bas(t_game *jeux)
{
	if(jeux->map[jeux->y + 1][jeux->x ] == '1')
		return;
	else if(jeux->map[jeux->y + 1][jeux->x] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y + 1 ][jeux->x] = 'P';
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y + 1][jeux->x] = 'P';
	remplir_map(jeux);
}
void ft_haut(t_game *jeux)
{
	if(jeux->map[jeux->y - 1][jeux->x] == '1')
		return;
	else if(jeux->map[jeux->y - 1][jeux->x] == 'C')
	{
		jeux->map[jeux->y][jeux->x] = '0';
		jeux->map[jeux->y - 1][jeux->x ] = 'P';
	}
	jeux->map[jeux->y][jeux->x] = '0';
	jeux->map[jeux->y - 1][jeux->x] = 'P';
	remplir_map(jeux);
}
int	key_hook(int keycode, t_game *jeux)
{
	(void)jeux;
	printf("Hello from key_hook! %d\n", keycode);
	cherche_player(jeux);
	if(keycode == 0)
		ft_gauche(jeux);
	if(keycode == 2)
		ft_droit(jeux);
	if(keycode == 13)
		ft_haut(jeux);
	if(keycode == 1)
		ft_bas(jeux);
	return (0);
	
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
	x = jeux.lnmap * 60;
	y = jeux.longeur_map * 70;
	jeux.win = mlx_new_window(jeux.mlx, x, y, "so_long");
	conver_image(&jeux);
	remplir_map(&jeux);
	mlx_key_hook(jeux.win, &key_hook, &jeux);
	
	mlx_loop(jeux.mlx);
	// int i;
	// i = 0;
	// while(jeux.map[i])da
	// {
	// 	printf("%s\n" , jeux.map[i]);
	// 	i++;
	// }
}
	
