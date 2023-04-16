/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:16:47 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 21:28:42 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_tom_gauche(t_game_bonus *jeux, int i, int j)
{
	if (jeux->map[i][j - 1] == '1' || jeux->map[i][j - 1] == 'C'
	|| jeux->map[i][j - 1] == 'E')
		return ;
	if (jeux->map[i][j - 1] == 'P')
	{
		jeux->map[i][j] = '0';
		jeux->map[i][j - 1] = 'N';
		ft_message_erreur_bonus("game over\n");
		free_bonus_map(jeux->map);
		exit(1);
	}
	jeux->map[i][j] = '0';
	jeux->map[i][j - 1] = 'N';
}

void	ft_move_tom_droit(t_game_bonus *jeux, int i, int j)
{
	if (jeux->map[i][j + 1] == '1' || jeux->map[i][j + 1] == 'C'
	|| jeux->map[i][j + 1] == 'E')
		return ;
	if (jeux->map[i][j + 1] == 'P')
	{
		jeux->map[i][j] = '0';
		jeux->map[i][j + 1] = 'N';
		ft_message_erreur_bonus("game over\n");
		free_bonus_map(jeux->map);
		exit(1);
	}
	jeux->map[i][j] = '0';
	jeux->map[i][j + 1] = 'N';
}

void	ft_move_tom_haut(t_game_bonus *jeux, int i, int j)
{
	if (jeux->map[i + 1][j] == '1' || jeux->map[i + 1][j] == 'E'
	|| jeux->map[i + 1][j] == 'C')
		return ;
	if (jeux->map[i + 1][j] == 'P')
	{
		jeux->map[i][j] = '0';
		jeux->map[i + 1][j] = 'N';
		ft_message_erreur_bonus("game over\n");
		free_bonus_map(jeux->map);
		exit(1);
	}
	jeux->map[i][j] = '0';
	jeux->map[i + 1][j] = 'N';
}

void	ft_move_tom_bas(t_game_bonus *jeux, int i, int j)
{
	if (jeux->map[i - 1][j] == '1' || jeux->map[i - 1][j] == 'E'
	|| jeux->map[i - 1][j] == 'C')
		return ;
	if (jeux->map[i - 1][j] == 'P')
	{
		jeux->map[i][j] = '0';
		jeux->map[i - 1][j] = 'N';
		ft_message_erreur_bonus("game over\n");
		free_bonus_map(jeux->map);
		exit(1);
	}
	jeux->map[i][j] = '0';
	jeux->map[i - 1][j] = 'N';
}

void	move_tom(t_game_bonus *jeux, int i, int j)
{
	int	rand;

	if (jeux->map[i][j] == 'N')
	{
		rand = arc4random_uniform(4);
		if (rand == 0)
			ft_move_tom_gauche(jeux, i, j);
		else if (rand == 1)
			ft_move_tom_droit(jeux, i, j);
		else if (rand == 2)
			ft_move_tom_haut(jeux, i, j);
		else if (rand == 3)
			ft_move_tom_bas(jeux, i, j);
	}
}
