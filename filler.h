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
	char 	l_bot;
	size_t	i;
	size_t	j;
	int		size_m[2];
	int 	size_f[2];
	size_t n;
	size_t m;
	size_t count;
	size_t count_all;


}				t_fill;

t_fill		*get_mem(void);
void		get_piece(t_fill *fill, char *str);
void		write_piece(t_fill *fill, char *str);
void		write_plateau(t_fill *fill, char *str);
void		get_plateau(t_fill *fill, char *str);
void		get_player(t_fill *fill, char *str);
void		search(t_fill *fill);
void		clear(t_fill *new);
#endif
