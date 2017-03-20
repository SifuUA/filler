/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:22:48 by okres             #+#    #+#             */
/*   Updated: 2016/12/09 14:08:05 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					minus;
	unsigned long long	res;

	res = 0;
	minus = 1;
	i = skip(str);
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res > 9223372036854775807 && minus == -1)
			return (0);
		if (res > 9223372036854775807)
			return (-1);
	}
	return ((int)(res * minus));
}
