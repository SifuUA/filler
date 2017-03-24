/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bla_bla.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:57:02 by okres             #+#    #+#             */
/*   Updated: 2017/03/24 19:59:59 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_player(t_fill *fill, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == fill->player)
			return (1);
		i++;
	}
	return (0);
}

int		find_bott(t_fill *fill, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == fill->bot || str[i] == fill->l_bot)
			return (1);
		i++;
	}
	return (0);
}

int		find_left_b(t_fill *fill)
{
	int i;
	int j;
	int min_x;

	i = 0;
	min_x = 0;
	while (i < fill->size_m[0] - 1)
	{
		j = 0;
		while (j < fill->size_m[1] - 1)
		{
			if (fill->plateau[i][j] == fill->bot ||
					fill->plateau[i][j] == fill->l_bot)
			{
				if (min_x < j)
					min_x = j;
			}
			j++;
		}
		i++;
	}
	return (min_x);
}

int		find_first_p(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (i < fill->size_m[0] - 1)
	{
		j = 0;
		while (j < fill->size_m[1] - 1)
		{
			if (fill->plateau[i][j] == fill->player)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

t_point	*find_bot(t_fill *fill, int flag)
{
	int		y;
	int		x;
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	y = 0;
	while (y < fill->size_m[0])
	{
		x = 0;
		while (x < fill->size_m[1])
		{
			if ((fill->plateau[y][x] == fill->bot || fill->plateau[y][x] ==
						fill->l_bot) && !find_player(fill, fill->plateau[y]) &&
					fill->plateau[y][0] == '.' && x > 1)
			{
				p->y = y;
				p->x = x;
				return (p);
			}
			x++;
		}
		y++;
	}
	analize(p, fill, flag);
	return (p);
}
