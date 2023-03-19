/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:08:38 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/18 12:51:14 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	ft_word_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != 0 && str[i] == c)
			i++;
		if (str[i])
			count = count + 1;
		while (str[i] != 0 && str[i] != c)
			i++;
		while (str[i] != 0 && str[i] == c)
			i++;
	}
	return (count);
}

static	char	**ft_fre(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
	return (NULL);
}

static	char	*alloc_words(char *s, int start, int finish)
{
	int		i;
	char	*word;

	i = 0;
	word = (char*) malloc(sizeof(*s) * (finish - start) + 1);
	if (!word)
		return (NULL);
	while (s[i] && start < finish)
	{
		word[i] = s[start];
		start ++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static	char	**fill_str(t_spl *spl, char *s, char c)
{
	while (spl->i <= spl->len)
	{
		if (s[spl->i] != c && spl->index < 0)
			spl->index = spl->i;
		else if ((s[spl->i] == c || spl->i == spl->len) && spl->index >= 0)
		{
			spl->ptr[spl->j] = alloc_words((char*)s, spl->index, spl->i);
			if (!spl->ptr[spl->j])
			{
				ft_fre (spl->ptr);
				return (NULL);
			}
			spl->j++;
			spl->index = -1;
		}
		spl->i++;
	}
	spl->ptr[spl->j] = NULL;
	return (spl->ptr);
}

char	**ft_split(char *s, char c)
{
	t_spl	spl;

	spl.i = 0;
	spl.j = 0;
	if (!s)
		return (NULL);
	spl.len = ft_strlen(s);
	spl.index = -1;
	spl.count = ft_word_count((char*)s, c);
	spl.ptr = malloc(sizeof(char*) * (spl.count + 1));
	if (!spl.ptr)
		return (NULL);
	fill_str(&spl, (char*)s, c);
	return (spl.ptr);
}

// #include <stdio.h>
// int main()
// {
// 	char*str;
// 	int i;
// 	i = 0;
// 	char**spl;
	
// 	str = "manar.ben.sal";
// 	spl = ft_split(str,'.');

// 	while(spl[i])
// 	{
		
// 		printf("%s\n", spl[i]);
// 		i++;
// 	}
// 	return 0;
// }
