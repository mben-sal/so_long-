/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_erreur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:45:00 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 17:28:55 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message_erreur(char *str)
{
	ft_putstr(str);
	exit(1);
}

// char	free_map(char **s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		free(s[i++]);
// 	}
// 	free(s);
// 	return (NULL);
// }