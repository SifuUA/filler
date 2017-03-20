/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:22:49 by okres             #+#    #+#             */
/*   Updated: 2016/12/10 13:23:47 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict str1, const char *restrict str2)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str1);
	while (str2[i] != '\0')
	{
		str1[len] = str2[i];
		len++;
		i++;
	}
	str1[len] = '\0';
	return (str1);
}
