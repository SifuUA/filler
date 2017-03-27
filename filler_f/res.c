/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:54:44 by okres             #+#    #+#             */
/*   Updated: 2017/03/26 20:34:44 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	up_str(t_point **p, t_fill *fill)
{
	if (find_player(fill, fill->plateau[0]) && find_player(fill,
				fill->plateau[fill->size_m[0] - 1]) && fill->plateau[0][0] ==
			fill->player && fill->plateau[fill->size_m[0] - 1][0] !=
			fill->player)
	{
		(*p)->y = fill->size_m[0] - 1;
		(*p)->x = 0;
	}
	else if (fill->plateau[0][0] == fill->player &&
			fill->plateau[fill->size_m[0] - 1][0] == fill->player)
	{
		(*p)->y = 0;
		(*p)->x = fill->size_m[1] / 2;
	}
	else if (find_left_b(fill) && find_player(fill, fill->plateau[0])
			&& find_player(fill, fill->plateau[fill->size_m[0] - 1])
			&& !find_beg(fill))
	{
		(*p)->y = fill->size_m[0] - 1;
		(*p)->x = 0;
	}
}

void	up_strategy(t_point **p, t_fill *fill)
{
	if (find_bott(fill, fill->plateau[0]) && find_player(fill,
		fill->plateau[0]) && !find_player(fill,
			fill->plateau[fill->size_m[0] - 1]))
	{
		(*p)->y = fill->size_m[0] - 1;
		(*p)->x = fill->size_m[1] / 2 + fill->size_m[1] / 3;
	}
	else if (find_player(fill, fill->plateau[0])
			&& find_player(fill, fill->plateau[fill->size_m[0] - 1])
			&& fill->plateau[0][0] != fill->player
			&& !find_left_b(fill))
	{
		(*p)->y = 0;
		(*p)->x = 0;
	}
	up_str(p, fill);
}

void	analize(t_point *point, t_fill *fill, int flag)
{
	point->y = flag > 0 ? fill->size_m[0] / 2 : (fill->size_m[0]);
	point->x = flag > 0 ? fill->size_m[1] : 0;
	f_1(point, fill, flag);
	if (find_bott(fill, fill->plateau[fill->size_m[0] - 1])
			&& !find_end(fill))
	{
		point->y = fill->size_m[0] / 4 + fill->size_m[0] / 2;
		point->x = fill->size_m[1] - 1;
	}
	if (find_left_b(fill) && find_bott(fill, fill->plateau[fill->size_m[0] - 1])
			&& find_bott(fill, fill->plateau[0]) && fill->plateau[0][0] == '.')
	{
		point->y = 0;
		point->x = fill->size_m[1] / 4;
	}
	f_2(point, fill);
	if (flag > 0)
		up_strategy(&point, fill);
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
