/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:55:51 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 22:37:01 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_enemy_gauche(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y][jeux->x - 1] == 'N')
	{
		ft_message_erreur_bonus("game over");
		exit(1);
	}
}

void	ft_check_enemy_droit(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y][jeux->x + 1] == 'N')
	{
		ft_message_erreur_bonus("game over");
		exit(1);
	}
}

void	ft_check_enemy_bas(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y + 1][jeux->x] == 'N')
	{
		ft_message_erreur_bonus("game over");
		exit(1);
	}
}

void	ft_check_enemy_haut(t_game_bonus *jeux)
{
	if (jeux->map[jeux->y - 1][jeux->x] == 'N')
	{
		ft_message_erreur_bonus("game over");
		exit(1);
	}
}
