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
	int	i;
	size_t	j;
	int		size_m[2];
	int 	size_f[2];
	int n;
	int m;
	size_t count;
	size_t count_all;

}				t_fill;

t_fill		*get_mem(void);
void		get_piece(t_fill *fill, char *str);
void		write_piece(t_fill *fill, char *str);
void		write_plateau(t_fill *fill, char *str);
void		get_plateau(t_fill *fill, char *str);
void		get_player(t_fill *fill, char *str);
void		search(t_fill *fill, int flag);
void		clear(t_fill *new);
int 		find_player(t_fill *fill, char *str);
t_point		*find_bot(t_fill *fill, int flag);
t_point		*find_bot_revers(t_fill *fill, int flag);
t_point		*find_road(t_point *p, t_fill *fill, int flag);
int			manh_dist(int x, int y, int x1, int y1);
void		analize(t_point *point, t_fill *fill, int flag);
void		put_flag(t_fill *fill, char *str, int *flag);
int 		find_bott(t_fill *fill, char *str);
#endif
