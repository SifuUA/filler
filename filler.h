#ifndef FILLER_FILLER_H_H
#define FILLER_FILLER_H_H

# include "libft/libft.h"

typedef struct	s_point{
	int		x;
	int		y;
}				t_point;

typedef struct s_fill
{
	t_point point[1000];
	char	**plateau;
	char	**piece;
	char 	player;
	char 	bot;
	size_t	i;
	size_t	j;
	int		size_m[2];
	int 	size_f[2];

}				t_fill;


void		get_piece(t_fill *fill, char *str);
void		write_piece(t_fill *fill, char *str);
void		write_plateau(t_fill *fill, char *str);
void		get_plateau(t_fill *fill, char *str);
void		get_player(t_fill *fill, char *str);
#endif
