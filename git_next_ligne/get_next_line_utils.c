/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:10:32 by mben-sal          #+#    #+#             */
/*   Updated: 2023/04/15 22:06:34 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int 	ft_strlen(char*str)
{
	int 	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char*s1, char*s2)
{
	int		len;
	int		i;
	int		j;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char*)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strchr(char*str, int c)
{
	int 			i;
	int 			n;

	i = 0;
	n = ft_strlen(str);
	while (i < n)
	{
		if (str[i] == (char)c)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char*s1)
{
	int 	i;
	int 	len;
	char	*ptr;
	char	*str;

	i = 0;
	str = (char*)s1;
	len = ft_strlen(str);
	ptr = (char*)malloc(sizeof(char) *(len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, int start, int  len)
{
	int 	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= start + len)
		ptr = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
