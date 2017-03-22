#include "filler.h"

void	best_place(t_fill *fill)
{

}

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
	while (fill->n < fill->size_f[0])
	{
		fill->m = 0;
		while (fill->m < fill->size_f[1])
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

void	search(t_fill *fill)
{
	int x;
	int y;

	y = 0;
	fill->i = 0;
	while (fill->plateau[y] && fill->size_m[0] - y >= fill->size_f[0])
	{
		x = 0;
		while (x < fill->size_m[1] && fill->size_m[1] - x >= fill->size_f[1])
		{
			push_piece(y, x, fill);
			x++;
		}
		y++;
	}
	ft_putnbr_fd(fill->point->y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(fill->point->x, 1);
	ft_putchar_fd('\n', 1);
	clear(fill);
}

