/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:25:38 by okres             #+#    #+#             */
/*   Updated: 2016/12/02 16:24:45 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	char			*res;

	i = 0;
	if (!s)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	res = ptr;
	if (!ptr)
		return (NULL);
	while (*s)
	{
		*ptr++ = f(i, *(s++));
		i++;
	}
	return (res);
}
