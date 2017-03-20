#ifndef FILLER_FILLER_H_H
#define FILLER_FILLER_H_H

# include "libft/libft.h"

typedef struct s_fill
{
	char	**plateau;
	char	**piece;
	int 	player;
	size_t	*size_m[2];
	size_t 	*size_f[2];
}				t_fill;
#endif
