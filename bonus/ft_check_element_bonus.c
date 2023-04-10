/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_element_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:12:15 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/09 23:44:10 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int ft_lnmap_bonus(t_game_bonus *jeux)
{
	int i;

	i = 0;

	while (jeux->map[i])
	{
		if(jeux->map == NULL)
			break;
		i++;
	}
	return(i);
	
}
void ft_check_les_element_bonus(t_game_bonus *jeux)
{
	int j;
	int i;

	i = 0;
	ft_check_bonus(jeux);
	while(jeux->map[i])
	{
		j = 0;
		while(jeux->map[i][j])
		{
			if(jeux->map[i][j] == 'E')
				jeux->check_e++;
			if(jeux->map[i][j] == 'C')
				jeux->check_c++;
			if(jeux->map[i][j] == 'P')
				jeux->check_p++;
			j++;
		}
		i++;
	}
	if(jeux->check_c < 1 || jeux->check_e < 1 || jeux->check_p != 1)
		ft_message_erreur_bonus("erreur\n");
}
void ft_check_bonus (t_game_bonus *jeux)
{
	int j;
	int i;

	i = 0;
	while(jeux->map[i])
	{
		j = 0;
		while(jeux->map[i][j])
		{
			if(jeux->map[i][j] != '1' && jeux->map[i][j] != '0'&& jeux->map[i][j] != 'C' &&
			jeux->map[i][j] != 'P' && jeux->map[i][j] != 'E' && jeux->map[i][j] != 'N')
				ft_message_erreur_bonus("erreur\n");
			j++;
		}
		i++;
	}
}
void ft_check_rectangulaire_bonus (t_game_bonus *jeux)
{
	int longeur;
	int i;
	
	i = 1;
	jeux->lnmap = ft_strlen(jeux->map[0]);
	longeur = jeux->longeur_map;
	jeux->longeur_map = ft_lnmap_bonus(jeux);
	if ( jeux->lnmap ==  longeur )
		ft_message_erreur_bonus("erreur\n");
	while(jeux->map[i])
	{
		if(jeux->lnmap != ft_strlen(jeux->map[i]))
			ft_message_erreur_bonus("erreur\n");
		i++;
	}
}