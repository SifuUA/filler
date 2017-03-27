/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lit_lit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:48:37 by okres             #+#    #+#             */
/*   Updated: 2017/03/26 20:33:55 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		mini_hl(t_fill *fill, int flag)
{
	if (find_player(fill, fill->plateau[fill->size_m[0] - 2]) &&
		find_bott(fill, fill->plateau[fill->size_m[0] - 2]) && flag < 0
		&& (fill->plateau[fill->size_m[0] / 4][1] == fill->player ||
			fill->plateau[fill->size_m[0] / 4 + 1][1] == fill->player) &&
		find_player(fill, fill->plateau[0]) && !find_end(fill))
		return (1);
	return (0);
}

int		l_h_1(t_fill *fill, int flag)
{
	if (find_player(fill, fill->plateau[fill->size_m[0] - 2]) &&
		find_bott(fill, fill->plateau[fill->size_m[0] - 2]) && flag < 0
		&& (fill->plateau[fill->size_m[0] / 4][1] != fill->player ||
			fill->plateau[fill->size_m[0] / 4 + 1][1] != fill->player) &&
		find_end(fill))
		return (1);
	return (0);
}

void	f_1(t_point *point, t_fill *fill, int flag)
{
	if (find_player(fill, fill->plateau[fill->size_m[0] - 1])
		&& find_beg(fill) && !find_end(fill) && find_bott(fill,
			fill->plateau[fill->size_m[0] - 1]))
	{
		point->y = fill->size_m[0] / 4;
		point->x = fill->size_m[1] - 1;
	}
	if (fill->plateau[fill->size_m[0]][0] == fill->player && flag < 0)
	{
		point->y = fill->size_m[0] / 2;
		point->x = 0;
	}
	if (l_h_1(fill, flag))
	{
		point->y = fill->size_m[0] / 4;
		point->x = 0;
	}
	if (mini_hl(fill, flag))
	{
		point->y = fill->size_m[0] / 4 + fill->size_m[0] / 2;
		point->x = fill->size_m[1] - 1;
	}
}

void	f_2(t_point *point, t_fill *fill)
{
	if (find_player(fill, fill->plateau[fill->size_m[0] - 1]) && find_beg(fill)
			&& find_end(fill) && fill->plateau[0][0] == '.' &&
			find_player(fill, fill->plateau[0]))
	{
		point->y = 0;
		point->x = fill->size_m[1] / 4;
	}
	else if (!find_bott(fill, fill->plateau[fill->size_m[0] - 1]) &&
			!find_bott(fill, fill->plateau[0]))
	{
		point->y = fill->size_m[1] / 3;
		point->x = 5;
	}
}
