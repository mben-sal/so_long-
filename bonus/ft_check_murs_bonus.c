/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_murs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:19:54 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 00:21:22 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_murs_bonus(t_game_bonus *jeux)
{
	int	i;
	int	j;
	int	ln_ligne;

	j = 0;
	ln_ligne = ft_strlen(jeux->map[0]);
	i = 0;
	while (jeux->map[i])
	{
		if (jeux->map[i][0] != '1' || jeux->map[i][ln_ligne - 1] != '1')
			ft_message_erreur_bonus("erreur : map besion d'un murs\n");
		i++;
	}
	ft_murs_bonus(jeux);
}

void	ft_murs_bonus(t_game_bonus *jeux)
{
	int	j;
	int	ln_ligne;

	j = 0;
	ln_ligne = ft_strlen(jeux->map[0]);
	while (jeux->map[0][j])
	{
		if (jeux->map[0][j] != '1')
			ft_message_erreur_bonus("erreur : map besion d'un murs\n");
		j++;
	}
	j = 0;
	while (jeux->map[jeux->longeur_map - 1][j])
	{
		if (jeux->map[jeux->longeur_map - 1][j] != '1')
			ft_message_erreur_bonus("erreur : map besion d'un murs\n");
		j++;
	}
}
