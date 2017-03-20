/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:15:17 by okres             #+#    #+#             */
/*   Updated: 2016/12/10 14:15:21 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*res;

	if (!s)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	res = ptr;
	if (!ptr)
		return (NULL);
	while (*s)
	{
		*ptr++ = f(*(s++));
	}
	return (res);
}
