#include "filler.h"

static void		get_plateau(t_fill *fill, char *str)
{
	char *tmp;


	if (str[0] == 'P' && str[1] == 'l')
	{
		tmp = str;
		tmp += 8;
		fill->size_m[0] = (size_t)ft_atoi(tmp);
		while (*tmp != ' ')
		{
			tmp++;
		}
		tmp++;
		fill->size_m[1] = (size_t)ft_atoi(tmp);
		ft_strdel(&tmp);
	}
}

static void		get_player(t_fill *fill, char *str)
{
	if (str[0] == '$' && str[9] == 'p')
	{
		if (str[10] == '1')
			fill->player = '1';
		else if (str[10] == '2')
			fill->player = 2;
	}
}

static void 	write_in(t_fill *fill)
{
	char 	*str;

	str = (char *)malloc(sizeof(char) * 1000);
	if (!str)
		exit(1);
	while (get_next_line(0, &str))
	{
		get_player(fill, str);
		get_plateau(fill, str);

	}
}

t_fill			*get_mem(void)
{
	t_fill	*new;

	new = malloc(sizeof(t_fill));
	if (!new)
		exit(1);
	new->plateau = (char **)malloc(sizeof(char *) * 1000);
	if (!new->plateau)
		exit(1);
	ft_bzero(new->plateau, 1000);
	new->piece = (char **)malloc(sizeof(char *) * 1000);
	if (!new->piece)
		exit(1);
	ft_bzero(new->piece, 1000);
	new->size_f[0] = 0;
	new->size_f[1] = 0;
	new->size_m[0] = 0;
	new->size_m[1] = 0;
	return (new);
}

int 	main(void)
{
	t_fill *fill;

	fill = get_mem();
	write_in(fill);
}

