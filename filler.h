#ifndef FILLER_FILLER_H_H
#define FILLER_FILLER_H_H

# include "libft/libft.h"

typedef struct s_fill
{
	char	**plateau;
	char	**piece;
	int 	player;
	size_t	size_m[2];
	size_t 	size_f[2];
}				t_fill;

void		get_piece(t_fill *fill, char *str);
void		write_piece(t_fill *fill, char *str);
void		write_plateau(t_fill *fill, char *str);
void		get_plateau(t_fill *fill, char *str);
void		get_player(t_fill *fill, char *str);
#endif
