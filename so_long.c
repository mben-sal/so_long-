/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:59:36 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/24 00:31:30 by mben-sal         ###   ########.fr       */
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
}

int main(int ac , char **av)
{
	t_game jeux;
	int x;
	int y;
	
	if (ac != 2)
		ft_message_erreur(1);
	initVar(&jeux);
	ft_check_map(av[1]);
	ft_validation_map(av[1] , &jeux);
	jeux.lnmap = ft_strlen(jeux.map[0]);
	jeux.longeur_map = ft_lnmap(&jeux);
	ft_so_long(&jeux);
	jeux.mlx = mlx_init();
	x = jeux.lnmap  * 60;
	y = jeux.longeur_map * 70;
	jeux.win = mlx_new_window(jeux.mlx, x, y, "so_long");
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
	
