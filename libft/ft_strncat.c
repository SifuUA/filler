/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:03:23 by okres             #+#    #+#             */
/*   Updated: 2016/12/07 17:13:40 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict str1, const char *restrict str2, size_t n)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(str1);
	while (i < n && str2[i])
	{
		str1[len] = str2[i];
		len++;
		i++;
	}
	str1[len] = '\0';
	return (str1);
}
