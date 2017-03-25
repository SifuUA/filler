/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:54:44 by okres             #+#    #+#             */
/*   Updated: 2017/03/24 21:55:33 by okres            ###   ########.fr       */
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

void	analize(t_point *point, t_fill *fill, int flag)
{
	point->y = flag > 0 ? fill->size_m[0] / 2 : (fill->size_m[0]);
	point->x = flag > 0 ? fill->size_m[1] : 0;
	if (find_player(fill, fill->plateau[fill->size_m[0] - 1])
		&& find_beg(fill) && !find_end(fill))
	{
		point->y = fill->size_m[0] / 4;
		point->x = fill->size_m[1] - 1;
	}
	else if (fill->plateau[fill->size_m[0]][0] == fill->player && flag < 0)
	{
		point->y = fill->size_m[0] / 2;
		point->x = 0;
	}
	else if (l_h_1(fill, flag))
	{
		point->y = fill->size_m[0] / 4;
		point->x = 0;
	}
	else if (mini_hl(fill, flag))
	{
		point->y = fill->size_m[0] / 4 + fill->size_m[0] / 2;
		point->x = fill->size_m[1] - 1;
	}
	else if (find_bott(fill, fill->plateau[fill->size_m[0] - 1])
			&& !find_end(fill))
	{
		point->y = fill->size_m[0] / 4 + fill->size_m[0] / 2;
		point->x = fill->size_m[1] - 1;
	}
}

void	search(t_fill *fill, int flag)
{
	int		x;
	int		y;
	t_point	*p_b;

	y = 0;
	fill->i = 0;
	while (y < fill->size_m[0])
	{
		x = 0;
		while (x < fill->size_m[1])
		{
			push_piece(y, x, fill);
			x++;
		}
		y++;
	}
	p_b = find_road(flag > 0 ? find_bot(fill, flag) : find_bot_revers(fill,
				flag), fill, flag);
	ft_putnbr_fd(p_b->y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(p_b->x, 1);
	ft_putchar_fd('\n', 1);
	clear(fill);

}
