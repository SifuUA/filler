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
