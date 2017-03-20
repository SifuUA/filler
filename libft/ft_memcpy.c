/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:39:15 by okres             #+#    #+#             */
/*   Updated: 2016/12/07 18:18:52 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src,
		size_t n)
{
	const char	*s_src;
	char		*s_dst;
	size_t		i;

	s_src = src;
	s_dst = dst;
	if (src < dst)
	{
		i = n;
		while (--i < n)
			s_dst[i] = s_src[i];
	}
	else
	{
		i = 0;
		--i;
		while (++i < n)
			s_dst[i] = s_src[i];
	}
	return (dst);
}
