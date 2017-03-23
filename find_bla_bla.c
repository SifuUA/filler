//
// Created by Oleksiy Kres on 3/22/17.
//

#include "filler.h"

int 	find_b(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (fill->plateau[i])
	{
		j = 0;
		while (fill->plateau[i][j])
		{
			if (fill->plateau[i][j] == fill->bot || fill->plateau[i][j]
													== fill->l_bot)
				return (1);
			else if (fill->plateau[i][j] == fill->player)
				return (0);
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
	int hz;
	int pz;




	i = 0;
	point = (t_point *)malloc(sizeof(t_point));
	min = manh_dist(p->x, p->y, fill->point[i].x,
					fill->point[i].y);
	point->y = fill->point[i].y;
	point->x = fill->point[i].x;
	pz = fill->size_m[0] - point->y;
	while (i < fill->i)
	{
		distance = manh_dist(p->x, p->y, fill->point[i].x,
							 fill->point[i].y);
		hz = fill->size_m[0] - point->y;
		if (min > distance && pz > hz)
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

int 	find_bott(t_fill *fill, char *str)
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

t_point *check(t_fill *fill)
{
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point));
	if (fill->plateau[0][fill->size_m[1]/ 2] == fill->player &&
			fill->plateau[fill->size_m[0]][fill->size_m[1]/ 2] == '.')
	{
		p->y = fill->size_m[0];
		p->x = fill->size_m[1]/ 2;
		return (p);
	}
	else if (fill->plateau[0][fill->size_m[1]/ 2] == '.' &&
			 fill->plateau[fill->size_m[0]][fill->size_m[1]/ 2] == fill->player)
	{
		p->y = 0;
		p->x = fill->size_m[1]/ 2;
		return (p);
	}
	else if (fill->plateau[0][fill->size_m[1]/ 2] == fill->player
			&& fill->plateau[fill->size_m[0]][fill->size_m[1]/ 2] == fill->player)
	{
		p->y = fill->size_m[0]/ 2;
		p->x = 0;
		return (p);
	}
	return (NULL);
}

t_point *check1(t_fill *fill)
{
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point));
	if (find_player(fill, fill->plateau[0]) && !find_bott(fill, fill->plateau[0]))
	{
		p->y = fill->size_m[0];
		p->x = 0;
		return (p);
	}
	return (NULL);
}

t_point	*find_bot_revers(t_fill *fill, int flag)
{
	int y;
	int x;
	t_point *p;
	t_point *d;

	p = (t_point *)malloc(sizeof(t_point));
	y = fill->size_m[0] - 1;
	while (y >= 0)
	{
		x = fill->size_m[1] - 1;
		while (x >= 0)
		{
			if ((d = check1(fill)) != NULL)
				return (d);
			if ((fill->plateau[y][x] == fill->bot ||
				 fill->plateau[y][x] == fill->l_bot) &&
				!find_player(fill, fill->plateau[y]) &&
				fill->size_m[0] - y > 2 )
			{
				p->y = y;
				p->x = x;
				return (p);
			}
			x--;
		}
		y--;
	}
	analize(p, fill, flag);
	return (p);
}

t_point	*find_bot(t_fill *fill, int flag)
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