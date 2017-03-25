/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:29:20 by okres             #+#    #+#             */
/*   Updated: 2017/03/24 21:30:35 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft/libft.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define CLEARE            "\033[2J"
# define TO_BEGIN        "\033[0;0f"

typedef struct	s_point{
	int		x;
	int		y;
}				t_point;

typedef struct	s_fill
{
	t_point		point[1000];
	char		**plateau;
	char		**piece;
	char		player;
	char		bot;
	char		l_bot;
	int			i;
	size_t		j;
	int			size_m[2];
	int			size_f[2];
	int			n;
	int			m;
	size_t		count;
	size_t		count_all;
	int			min;
	int			pz;
	int			k;
	int			distance;
	int			hz;
}				t_fill;

t_fill			*get_mem(void);
void			get_piece(t_fill *fill, char *str);
void			write_piece(t_fill *fill, char *str);
void			write_plateau(t_fill *fill, char *str);
void			get_plateau(t_fill *fill, char *str);
void			get_player(t_fill *fill, char *str);
void			search(t_fill *fill, int flag);
void			clear(t_fill *new);
int				find_player(t_fill *fill, char *str);
t_point			*find_bot(t_fill *fill, int flag);
t_point			*find_bot_revers(t_fill *fill, int flag);
t_point			*find_road(t_point *p, t_fill *fill, int flag);
int				manh_dist(int x, int y, int x1, int y1);
void			analize(t_point *point, t_fill *fill, int flag);
void			put_flag(t_fill *fill, char *str, int *flag);
int				find_bott(t_fill *fill, char *str);
int				find_first_p(t_fill *fill);
int				find_left_b(t_fill *fill);
int				find_end(t_fill *fill);
int				find_beg(t_fill *fill);
void			push_piece(int y, int x, t_fill *fill);
#endif
