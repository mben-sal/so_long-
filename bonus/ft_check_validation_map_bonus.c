/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validation_map_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:46:57 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/16 22:15:45 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_bonus(char *map)
{
	int	i;

	i = ft_strlen(map);
	while (map[i - 1])
	{
		if (map[i] == '.')
		{
			if (ft_strncmp(&map[i], ".ber") != 0)
			{
				ft_message_erreur_bonus("erreur : .ber\n");
			}
		}
		i--;
	}
}

void	ft_validation_map_bonus(char *av, t_game_bonus *jeux)
{
	char	*ligne;
	char	*des_lignes;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_message_erreur_bonus("erreur : aucune fiches\n");
	des_lignes = ft_strdup("");
	while (1)
	{
		ligne = get_next_line(fd);
		if (ligne == NULL)
		{
			free (ligne);
			break ;
		}
		if (ligne[0] == '\n')
			ft_message_erreur_bonus("erreur :ligne vide dans map\n");
		ft_free(&des_lignes, ft_strjoin(des_lignes, ligne), des_lignes);
		free(ligne);
	}
	if (des_lignes[0] == '\0')
		ft_message_erreur_bonus("erreur : ligne vide \n");
	jeux->map = ft_split(des_lignes, '\n');
	free(des_lignes);
}
