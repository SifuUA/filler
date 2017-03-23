#include "filler.h"

void 	write_in(t_fill *fill)
{
	char 	*str;
	static int flag;

	fill->i = 0;
	fill->j = 0;
	str = (char *)malloc(sizeof(char) * 1000);
	if (!str)
		exit(1);
	while (get_next_line(0, &str))
	{
		get_player(fill, str);
		get_plateau(fill, str);
		get_piece(fill, str);
		write_plateau(fill, str);
		write_piece(fill, str);
		put_flag(fill, str, &flag);
		ft_strdel(&str);
		if (fill->i == fill->size_f[0] && fill->i > 0)
			search(fill, flag);
	}
}

int 	main(void)
{
	t_fill *fill;

	fill = get_mem();
	write_in(fill);
}

