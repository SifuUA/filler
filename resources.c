/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:41:35 by okres             #+#    #+#             */
/*   Updated: 2017/03/24 21:54:40 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_beg(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (fill->plateau[i])
	{
		j = 0;
		while (fill->plateau[i][j])
		{
			if (fill->plateau[i][0] == fill->player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		find_end(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (fill->plateau[i])
	{
		j = 0;
		while (fill->plateau[i][j])
		{
			if (fill->plateau[i][fill->size_m[1] - 1] == fill->player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	record(t_fill *fill, int y, int x)
{
	fill->point[fill->i].x = x;
	fill->point[fill->i].y = y;
	fill->i++;
}

int		l_h(t_fill *fill, int y, int x)
{
	if (fill->piece[fill->n][fill->m] == '*' &&
		(fill->plateau[y + fill->n][x + fill->m] == fill->bot ||
		fill->plateau[y + fill->n][x + fill->m] == fill->l_bot))
		return (1);
	return (0);
}

void	push_piece(int y, int x, t_fill *fill)
{
	fill->n = 0;
	fill->count = 0;
	fill->count_all = 0;
	while (fill->n < fill->size_f[0] &&
			y + fill->size_f[0] <= fill->size_m[0])
	{
		fill->m = 0;
		while (fill->m < fill->size_f[1] &&
				x + fill->size_f[1] <= fill->size_m[1])
		{
			if (fill->piece[fill->n][fill->m] == '*' &&
					fill->plateau[y + fill->n][x + fill->m] == fill->player)
				fill->count++;
			else if (l_h(fill, y, x))
				return ;
			else if (fill->count > 1)
				return ;
			fill->count_all++;
			fill->m++;
		}
		fill->n++;
	}
	if (fill->count == 1 && fill->count_all ==
			fill->size_f[0] * fill->size_f[1])
		record(fill, y, x);
}
