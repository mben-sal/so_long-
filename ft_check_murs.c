/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_murs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:23:58 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 13:41:03 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_murs(t_game *jeux)
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
			ft_message_erreur("erreur\n");
		i++;
	}
	ft_murs(jeux);
}

void	ft_murs(t_game *jeux)
{
	int	j;
	int	ln_ligne;

	j = 0;
	ln_ligne = ft_strlen(jeux->map[0]);
	while (jeux->map[0][j])
	{
		if (jeux->map[0][j] != '1')
			ft_message_erreur("erreur\n");
		j++;
	}
	j = 0;
	while (jeux->map[jeux->longeur_map - 1][j])
	{
		if (jeux->map[jeux->longeur_map - 1][j] != '1')
			ft_message_erreur("erreur\n");
		j++;
	}
}
