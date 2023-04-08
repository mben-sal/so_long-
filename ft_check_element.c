/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:45:57 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/08 13:58:25 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int ft_lnmap(t_game *jeux)
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
void ft_check_les_element(t_game *jeux)
{
	int j;
	int i;

	i = 0;
	ft_check(jeux);
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
		ft_message_erreur("erreur\n");
}
void ft_check(t_game *jeux)
{
	int j;
	int i;

	i = 0;
	while(jeux->map[i])
	{
		j = 0;
		while(jeux->map[i][j])
		{
			if(jeux->map[i][j] != '1' && jeux->map[i][j] != '0'&& jeux->map[i][j] != 'C' && jeux->map[i][j] != 'P' && jeux->map[i][j] != 'E')
				ft_message_erreur("erreur\n");
			j++;
		}
		i++;
	}
}
void ft_check_rectangulaire(t_game *jeux)
{
	int longeur;
	int i;
	
	i = 1;
	jeux->lnmap = ft_strlen(jeux->map[0]);
	longeur = jeux->longeur_map;
	jeux->longeur_map = ft_lnmap(jeux);
	if ( jeux->lnmap ==  longeur )
		ft_message_erreur("erreur\n");
	while(jeux->map[i])
	{
		if(jeux->lnmap != ft_strlen(jeux->map[i]))
			ft_message_erreur("erreur\n");
		i++;
	}
}