/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:18:45 by okres             #+#    #+#             */
/*   Updated: 2016/12/08 18:18:52 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size == 0)
		return (lens);
	if ((size - 1) < lend)
		return (size + lens);
	i = 0;
	while (dst[i])
		i++;
	size = size + lend;
	while (*src && i < (size - lend - 1))
		dst[i++] = *(src++);
	dst[i] = 0;
	return (lend + lens);
}
