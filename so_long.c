/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:59:36 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 17:28:59 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_so_long(t_game *jeux)
{
	int	i;

	i = 0;
	ft_check_rectangulaire(jeux);
	ft_check_murs(jeux);
	ft_check_les_element(jeux);
	copier_map(jeux);
	ft_validation_chemin(jeux);
}

void	initvar(t_game *jeux)
{
	jeux->check_c = 0;
	jeux->check_e = 0;
	jeux->check_p = 0;
	jeux->lnmap = ft_strlen(jeux->map[0]);
	jeux->longeur_map = ft_lnmap(jeux);
}

int	key_hook(int keycode, t_game *jeux)
{
	cherche_player(jeux);
	if (keycode == 0)
		ft_gauche(jeux);
	if (keycode == 2)
		ft_droit(jeux);
	if (keycode == 13)
		ft_haut(jeux);
	if (keycode == 1)
		ft_bas(jeux);
	if (keycode == 53)
		exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	jeux;
	int		x;
	int		y;

	if (ac != 2)
		ft_message_erreur("erreur\n");
	ft_check_map(av[1]);
	ft_validation_map(av[1], &jeux);
	initvar(&jeux);
	ft_so_long(&jeux);
	jeux.mlx = mlx_init();
	conver_image(&jeux);
	jeux.m = 0;
	x = jeux.lnmap * 60;
	y = jeux.longeur_map * 70;
	jeux.win = mlx_new_window(jeux.mlx, x, y, "so_long");
	remplir_map(&jeux);
	mlx_key_hook(jeux.win, &key_hook, &jeux);
	mlx_loop(jeux.mlx);
	// free_map(jeux.map);
}