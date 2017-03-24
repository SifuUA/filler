#include "filler.h"

t_point	*find_road(t_point *p, t_fill *fill, int flag)
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
		hz = fill->size_m[0] - fill->point[i].y;
		if (min > distance && flag > 0)
		{
			point->y = fill->point[i].y;
			point->x = fill->point[i].x;
			min = distance;
		}
		else if (min >= distance && flag < 0 && pz <= hz && !find_player(fill, fill->plateau[0])
				 && !find_player(fill, fill->plateau[1]))
		{
			point->y = fill->point[i].y;
			point->x = fill->point[i].x;
			min = distance;
		}
		else if (min > distance && flag < 0 && (find_player(fill, fill->plateau[0]) || find_player(fill, fill->plateau[1])))
		{
			point->y = fill->point[i].y;
			point->x = fill->point[i].x;
			min = distance;
		}

		i++;
	}
	return (point);
}

t_point	*find_bot_revers(t_fill *fill, int flag)
{
	int y;
	int x;
	t_point *p;
	t_point *d;

	p = (t_point *)malloc(sizeof(t_point));
	y = fill->size_m[0] - 1;
	if (find_left_b(fill) > find_first_p(fill) && !find_player(fill, fill->plateau[0]))
	{
		if (fill->plateau[fill->size_m[0]][0] == fill->player)
		{
			p->y = fill->size_m[0]/2 ;
			p->x = flag > 0 ? fill->size_m[1] : 0;
		}
		p->y = 0;
		p->x = fill->size_m[1];
		return (p);
	}
	while (y >= 0)
	{
		x = fill->size_m[1] - 1;
		while (x >= 0)
		{
			if ((fill->plateau[y][x] == fill->bot ||
				 fill->plateau[y][x] == fill->l_bot) &&
				!find_player(fill, fill->plateau[y]) &&
				fill->size_m[0] - y > 2 && find_player(fill, fill->plateau[1]))
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

void	put_flag(t_fill *fill, char *str, int *flag)
{
	int i;

	i = 0;
	if (*flag == 0)
	{
		while (str[i])
		{
			if (str[i] == fill->bot || str[i] == fill->l_bot)
			{
				*flag = -777;
				break ;
			}
			else if (str[i] == fill->player)
			{
				*flag = 777;
				break;
			}
			i++;
		}
	}
}

void			clear_arr(char **ar, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		ft_bzero(ar[i], ft_strlen(ar[i]));
		i++;
	}
}

void			clear(t_fill *new)
{
	clear_arr(new->plateau, new->size_m[0]);
	clear_arr(new->piece, new->size_f[0]);
	new->size_f[0] = 0;
	new->size_f[1] = 0;
	new->size_m[0] = 0;
	new->size_m[1] = 0;
	new->i--;
	while (new->i >= 0)
	{
		new->point[new->i].y = 0;
		new->point[new->i].x = 0;
		new->i --;
	}
	new->i = 0;
	new->j = 0;
}

int		manh_dist(int x, int y, int x1, int y1)
{
	int	res;
	int	res1;

	res = (x - x1);
	res1 = (y - y1);
	if (res < 0)
		res = -res;
	if (res1 < 0)
		res1 = -res1;
	return (res + res1);
}
