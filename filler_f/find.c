/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:08:52 by okres             #+#    #+#             */
/*   Updated: 2017/03/24 21:28:36 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_b_r(t_fill *fill, t_point **p, int flag)
{
	if (fill->plateau[fill->size_m[0]][0] == fill->player)
	{
		(*p)->y = fill->size_m[0] / 2;
		(*p)->x = flag > 0 ? fill->size_m[1] : 0;
	}
	else
	{
		(*p)->y = 0;
		(*p)->x = fill->size_m[1];
	}
}

int		buuu(t_fill *fill, int y, int x)
{
	if ((fill->plateau[y][x] == fill->bot || fill->plateau[y][x] ==
				fill->l_bot) && !find_player(fill, fill->plateau[y]) &&
			fill->size_m[0] - y > 2 &&
	find_player(fill, fill->plateau[1]) && !find_end(fill))
		return (1);
	return (0);
}

void	ppp(t_point **p, t_fill *fill)
{
	(*p)->y = fill->n;
	(*p)->x = fill->m;
}

int		hhh(t_fill *fill)
{
	if (find_left_b(fill) > find_first_p(fill) &&
	!find_player(fill, fill->plateau[0]))
		return (1);
	return (0);
}

t_point	*find_bot_revers(t_fill *fill, int flag)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	fill->n = fill->size_m[0] - 1;
	if (hhh(fill))
	{
		find_b_r(fill, &p, flag);
		return (p);
	}
	while (fill->n >= 0)
	{
		fill->m = fill->size_m[1] - 1;
		while (fill->m >= 0)
		{
			if (buuu(fill, fill->n, fill->m))
			{
				ppp(&p, fill);
				return (p);
			}
			fill->m--;
		}
		fill->n--;
	}
	analize(p, fill, flag);
	return (p);
}
