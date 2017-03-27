/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:33:34 by okres             #+#    #+#             */
/*   Updated: 2017/03/24 21:38:33 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill	*get_mem(void)
{
	t_fill	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_fill));
	if (!new)
		exit(1);
	new->plateau = (char **)malloc(sizeof(char *) * 10000);
	!new->plateau ? exit(1) : new->plateau;
	while (i < 10000)
	{
		new->plateau[i] = (char *)malloc(sizeof(char ) * 10000);
		ft_bzero(new->plateau[i], 10000);
		i++;
	}
	i = 0;
	new->piece = (char **)malloc(sizeof(char *) * 10000);
	!new->piece ? exit(1) : new->piece;
	while (i < 10000)
	{
		new->piece[i] = (char *)malloc(sizeof(char ) * 10000);
		ft_bzero(new->piece[i], 10000);
		i++;
	}
	return (new);
}

void	mini_h(t_fill *fill, t_point **point)
{
	(*point)->y = fill->point[fill->k].y;
	(*point)->x = fill->point[fill->k].x;
	fill->min = fill->distance;
}

void	mini_hh(t_fill *fill, t_point **point)
{
	(*point)->y = fill->point[fill->k].y;
	(*point)->x = fill->point[fill->k].x;
	fill->min = fill->distance;
}

void	help_f_road(t_fill *fill, t_point *p, t_point **point, int flag)
{
	fill->k = 0;
	while (fill->k < fill->i)
	{
		fill->distance = manh_dist(p->x, p->y, fill->point[fill->k].x,
				fill->point[fill->k].y);
		fill->hz = fill->size_m[0] - fill->point[fill->k].y;
		if (fill->min > fill->distance && flag > 0)
		{
			(*point)->y = fill->point[fill->k].y;
			(*point)->x = fill->point[fill->k].x;
			fill->min = fill->distance;
		}
		else if (fill->min >= fill->distance && flag < 0 && fill->pz <= fill->hz
				&& !find_player(fill, fill->plateau[0]) && !find_player(fill,
					fill->plateau[1]))
			mini_hh(fill, point);
		else if (fill->min > fill->distance && flag < 0 && (find_player(fill,
						fill->plateau[0]) || find_player(fill,
							fill->plateau[1])))
			mini_h(fill, point);
		fill->k++;
	}
}

t_point	*find_road(t_point *p, t_fill *fill, int flag)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	fill->min = manh_dist(p->x, p->y, fill->point[0].x,
			fill->point[0].y);
	point->y = fill->point[0].y;
	point->x = fill->point[0].x;
	fill->pz = fill->size_m[0] - point->y;
	help_f_road(fill, p, &point, flag);
	return (point);
}
