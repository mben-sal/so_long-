/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:59:36 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/21 20:56:16 by mben-sal         ###   ########.fr       */
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

	if (ac != 2)
		ft_message_erreur(1);
	initVar(&jeux);
	ft_check_map(av[1]);
	ft_validation_map(av[1] , &jeux);
	ft_so_long(&jeux);
	jeux.mlx = mlx_init();
	jeux.win = mlx_new_window(jeux.mlx, 1800, 1000, "so_long");
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
	
