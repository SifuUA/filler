#include "filler.h"


void	record(t_fill *fill, int y, int x)
{
	fill->point[fill->i].x = x;
	fill->point[fill->i].y = y;
	fill->i++;
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
			else if (fill->piece[fill->n][fill->m] == '*' &&
					(fill->plateau[y + fill->n][x + fill->m] == fill->bot ||
							fill->plateau[y + fill->n][x + fill->m] == fill->l_bot))
				return ;
			else if (fill->count > 1)
				return ;
			fill->count_all++;
			fill->m++;
		}
		fill->n++;
	}
	if (fill->count == 1 && fill->count_all == fill->size_f[0] * fill->size_f[1])
		record(fill, y, x);
}

void	search(t_fill *fill, int flag)
{
	int x;
	int y;
	t_point *p_b;

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
	p_b = find_road(flag > 0 ? find_bot(fill, flag) : find_bot_revers(fill, flag), fill, flag);
	ft_putnbr_fd(p_b->y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(p_b->x, 1);
	ft_putchar_fd('\n', 1);
	clear(fill);

}

void	analize(t_point *point, t_fill *fill, int flag)//strategy
{
	point->y = flag > 0 ? fill->size_m[0]/2 : (fill->size_m[0]);
	point->x = flag > 0 ? fill->size_m[1] : 0;
}