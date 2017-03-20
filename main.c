#include "filler.h"

static void 	write_in(t_fill *fill)
{
	while (get_next_line(0, fill->plateau))
	{

	}
}

t_fill			*get_mem(t_fill * fill)
{

}

int 	main(void)
{
	t_fill *fill;

	fill = malloc(sizeof(t_fill));
	if (!fill)
		exit(1);
	fill->plateau = (char **)malloc(sizeof(char *) * 1000);
	fill->piece = (char **)malloc(sizeof(char *) * 1000);
	write_in(fill);
}

