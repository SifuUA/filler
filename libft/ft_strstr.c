/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:57:43 by okres             #+#    #+#             */
/*   Updated: 2016/12/07 17:48:12 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *ptr_big;
	const char *ptr_little;

	if ((!*big) && (!*little))
		return ((char*)big);
	while (*big)
	{
		ptr_big = big;
		ptr_little = little;
		while (*big && *ptr_little && *big == *ptr_little)
		{
			big++;
			ptr_little++;
		}
		if (!*ptr_little)
		{
			return ((char*)ptr_big);
		}
		big = ptr_big + 1;
	}
	return (NULL);
}
