/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:01:34 by okres             #+#    #+#             */
/*   Updated: 2017/02/23 14:12:36 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*split_start(const char *s, char c)
{
	const char	*tmp;

	if (s)
	{
		tmp = s;
		while (*tmp == c)
			tmp++;
		return (tmp);
	}
	else
		return (NULL);
}

static int			count_of_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s != c)
			s++;
		words++;
		s = split_start(s, c);
	}
	return (words);
}

static char			**create_arr(char const *s, char c)
{
	char		**arr;
	char		**buf;
	const char	*ptr;
	int			i;

	arr = ft_memalloc(sizeof(arr) * (count_of_words(s, c) + 1));
	if (!arr)
		return (NULL);
	buf = arr;
	while (*s)
	{
		ptr = s;
		i = 0;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		*(buf++) = ft_strsub(ptr, 0, i);
		if (*s)
			s = split_start(s, c);
	}
	*(buf) = 0;
	return (arr);
}

char				**ft_strsplit(char const *s, char c)
{
	if (s)
		s = split_start(s, c);
	else
		return (NULL);
	return (create_arr(s, c));
}
