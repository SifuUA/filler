//
// Created by Oleksiy Kres on 3/22/17.
//

#include "filler.h"

void	find_road(t_point *p, t_fill *fill)
{

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