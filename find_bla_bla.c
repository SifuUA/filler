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


t_point	*find_road(t_point *p, t_fill *fill)
{
	int i;
	int min;
	int distance;
	t_point *point;

	i = 0;
	point = (t_point *)malloc(sizeof(t_point));
	min = manh_dist(p->x, p->y, fill->point[i].x,
					fill->point[i].y);
	point->y = fill->point[i].y;
	point->x = fill->point[i].x;
	while (i < fill->i)
	{
		distance = manh_dist(p->x, p->y, fill->point[i].x,
							 fill->point[i].y);
		if (min > distance && !find_b(fill,
			fill->plateau[fill->point[i].y]))
		{
			point->x = fill->point[i].x;
			point->y = fill->point[i].y;
		}
		else if(min > distance && find_b(fill,
			fill->plateau[fill->point[i + 1].y]))
		{
			point->x = fill->point[i].x;
			point->y = fill->point[i].y;
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
				!find_player(fill, fill->plateau[y]))
			{
				p->y = y;
				p->x = x;
				return (p);
			}
			x++;
		}
		y++;
	}
	return (p);
}