//
// Created by Oleksiy Kres on 3/22/17.
//

#include "filler.h"

int 	find_b(t_fill *fill, char *str)
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

int		find_last_player(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (i < fill->size_m[0])
	{
		j = 0;
		while (j < fill->size_m[1])
		{
			if (fill->plateau[i][j] == fill->player &&
					find_b(fill, fill->plateau[i]))
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

t_point	*find_road(t_point *p, t_fill *fill)
{
	int i;
	int min;
	int distance;
	t_point *point;
	int last;

	i = 0;
	point = (t_point *)malloc(sizeof(t_point));
	min = manh_dist(p->x, p->y, fill->point[i].x,
					fill->point[i].y);
	last = find_last_player(fill);
	point->y = fill->point[i].y;
	point->x = fill->point[i].x;
	while (i < fill->i)
	{
		distance = manh_dist(p->x, p->y, fill->point[i].x,
							 fill->point[i].y);
		if (min > distance)
		{
			point->y = fill->point[i].y;
			point->x = fill->point[i].x;
			min = distance;
		}
		i++;
	}
	return (point);
}

int 	find_player(t_fill *fill, char *str)
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

t_point	*find_bot(t_fill *fill)
{
	int y;
	int x;
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point));
	y = 0;
	while (y < fill->size_m[0])
	{
		x = 0;
		while (x < fill->size_m[1])
		{
			if ((fill->plateau[y][x] == fill->bot ||
				 fill->plateau[y][x] == fill->l_bot) &&
				!find_player(fill, fill->plateau[y]) &&
					fill->size_m[1] - x > 2)
			{
				p->y = y;
				p->x = x;
				return (p);
			}
			x++;
		}
		y++;
	}
	analize(p, fill);
	return (p);
}