/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:28:34 by okres             #+#    #+#             */
/*   Updated: 2016/12/08 18:29:40 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	b;
	char	*tmp;
	int		flag;

	b = '\0' + c;
	if (b == '\0')
	{
		while (*str)
			str++;
		return ((char*)str);
	}
	tmp = (char*)str;
	flag = 0;
	while (*str)
	{
		if (*str == b)
		{
			tmp = (char*)str;
			flag = 1;
		}
		str++;
	}
	if (flag == 0)
		return (0);
	return (tmp);
}
