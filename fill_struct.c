#include "filler.h"

void		get_piece(t_fill *fill, char *str)
{
	char *tmp;

	if (str[0] == 'P' && str[1] == 'i')
	{
		tmp = str;
		tmp += 6;
		fill->size_f[0] = ft_atoi(tmp);
		while (*tmp != ' ')
		{
			tmp++;
		}
		tmp++;
		fill->size_f[1] = ft_atoi(tmp);
	}
}

void		write_piece(t_fill *fill, char *str)
{
	if (str[0] == '.' || str[0] == '*')
	{
		fill->piece[fill->i] = ft_strdup(str);
		fill->i++;
	}
}

void		write_plateau(t_fill *fill, char *str)
{
	if (str[3] == ' ' && (str[4] == '.' || str[4] == 'X' ||
						  str[4] == 'x' ||  str[4] == 'O' || str[4] == 'o'))
	{
		fill->plateau[fill->j] = ft_strdup(str+=4);
		fill->j++;
	}

}

void		get_plateau(t_fill *fill, char *str)
{
	char *tmp;

	if (str[0] == 'P' && str[1] == 'l')
	{
		tmp = str;
		tmp += 8;
		fill->size_m[0] = ft_atoi(tmp);
		while (*tmp != ' ')
		{
			tmp++;
		}
		tmp++;
		fill->size_m[1] = ft_atoi(tmp);
	}
}

void		get_player(t_fill *fill, char *str)
{
	if (str[0] == '$' && str[9] == 'p')
	{
		if (str[10] == '1')
		{
			fill->player = 'O';
			fill->bot = 'X';
			fill->l_bot = 'x';
		}
		else if (str[10] == '2')
		{
			fill->player = 'X';
			fill->bot = 'O';
			fill->l_bot = 'o';
		}
	}
}

