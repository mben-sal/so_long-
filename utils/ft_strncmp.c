/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:27:31 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/18 15:35:34 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strncmp(char *first, char *second)
{
	char	*f;
	char	*s;
	int 			i;

	f = first;
	s = second;
	i = 0;

	while ((f[i] && s[i]))
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		i++;
	}
	return (0);
}
