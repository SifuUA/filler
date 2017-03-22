#include "filler.h"

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
	new->i = 0;
	new->j = 0;
}

void			push_piece(int y, int x, t_fill *fill)
{
	size_t n;
	size_t m;
	size_t count;
	size_t count_all;

	n = 0;
	count = 0;
	count_all = 0;
	while (n < fill->size_f[0])
	{
		m = 0;
		while (m < fill->size_f[1])
		{
			if (fill->piece[n][m] == '*' && fill->plateau[y + n][x + m] == fill->player)
				count++;
			else if (fill->piece[n][m] == '*' && fill->plateau[y + n][x + m] == fill->bot)
				return ;
			else if (count > 1)
				return ;
			count_all++;
			m++;
		}
		n++;
	}
	if (count == 1 && count_all == fill->size_f[0] * fill->size_f[1])
	{
		fill->point[fill->i].x = x;
		fill->point[fill->i].y = y;
		fill->i++;
	}
}

void			search(t_fill *fill)
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

