/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:31:38 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 22:24:12 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_so_long_bonus(t_game_bonus *jeux)
{
	int		i;

	i = 0;
	ft_check_rectangulaire_bonus(jeux);
	ft_check_murs_bonus(jeux);
	ft_check_les_element_bonus(jeux);
	copier_map_bonus(jeux);
	ft_validation_chemin_bonus(jeux);
	free_bonus_map(jeux->map2);
}

void	initvar_bonus(t_game_bonus *jeux)
{
	jeux->check_c = 0;
	jeux->check_e = 0;
	jeux->check_p = 0;
	jeux->count = 0;
	jeux->n = 0;
	jeux->lnmap = ft_strlen(jeux->map[0]);
	jeux->longeur_map = ft_lnmap_bonus(jeux);
}

int	key_hook_bonus(int keycode, t_game_bonus *jeux)
{
	cherche_player_bonus(jeux);
	if (keycode == 0)
		ft_gauche_bonus(jeux);
	if (keycode == 2)
		ft_droit_bonus(jeux);
	if (keycode == 13)
		ft_haut_bonus(jeux);
	if (keycode == 1)
		ft_bas_bonus(jeux);
	if (keycode == 53)
		exit(1);
	return (0);
}

int	enemy(t_game_bonus *jeux)
{
	char	*str;

	str = ft_itoa(jeux->count);
	remplir_map_bonus(jeux);
	vitesse_tom(jeux);
	enemy_tom(jeux);
	vitesse_mouse_bonus(jeux);
	mlx_string_put(jeux->mlx, jeux->win, 15, 7, 0x00FFFF00, str);
	free (str);
	return (0);
}

int	main(int ac, char **av)
{
	t_game_bonus	jeux;
	int				x;
	int				y;

	if (ac != 2)
		ft_message_erreur_bonus("seul argument\n");
	ft_check_map_bonus(av[1]);
	ft_validation_map_bonus(av[1], &jeux);
	initvar_bonus(&jeux);
	ft_so_long_bonus(&jeux);
	jeux.mlx = mlx_init();
	conver_image_bonus(&jeux);
	jeux.m = 0;
	x = jeux.lnmap * 60;
	y = jeux.longeur_map * 70;
	jeux.win = mlx_new_window(jeux.mlx, x, y, "so_long");
	mlx_loop_hook(jeux.mlx, &enemy, &jeux);
	remplir_map_bonus(&jeux);
	mlx_key_hook(jeux.win, &key_hook_bonus, &jeux);
	mlx_hook(jeux.win, 17, (1L << 17), &fermer_window_bonus, &jeux);
	mlx_loop(jeux.mlx);
	free_bonus_map(jeux.map);
	return (0);
}
