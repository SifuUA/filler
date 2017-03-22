//
// Created by Oleksiy Kres on 3/22/17.
//
# include"filler.h"

t_fill			*get_mem(void)
{
	t_fill	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_fill));
	if (!new)
		exit(1);
	new->plateau = (char **)malloc(sizeof(char *) * 1000);
	!new->plateau ? exit(1) : new->plateau;
	while (i < 1000)
	{
		new->plateau[i] = (char *)malloc(sizeof(char ) * 1000);
		ft_bzero(new->plateau[i], 1000);
		i++;
	}
	i = 0;
	new->piece = (char **)malloc(sizeof(char *) * 1000);
	!new->piece ? exit(1) : new->piece;
	while (i < 1000)
	{
		new->piece[i] = (char *)malloc(sizeof(char ) * 1000);
		ft_bzero(new->piece[i], 1000);
		i++;
	}
	return (new);
}