#include "filler.h"

void		get_piece(t_fill *fill, char *str)
{
	char *tmp;

	if (str[0] == 'P' && str[1] == 'i')
	{
		tmp = str;
		tmp += 6;
		fill->size_f[0] = (size_t)ft_atoi(tmp);
		while (*tmp != ' ')
		{
			tmp++;
		}
		tmp++;
		fill->size_f[1] = (size_t)ft_atoi(tmp);
	}
}

void		write_piece(t_fill *fill, char *str)
{
	static int i;

	if (str[0] == '.' || str[0] == '*')
	{
		fill->piece[i] = ft_strdup(str);
		i++;
	}
}

void		write_plateau(t_fill *fill, char *str)
{
	static int i;

	if (str[3] == ' ' && (str[4] == '.' || str[4] == 'X' ||
						  str[4] == 'x' ||  str[4] == 'O' || str[4] == 'o'))
	{
		fill->plateau[i] = ft_strdup(str);
		i++;
	}

}

void		get_plateau(t_fill *fill, char *str)
{
	char *tmp;

	if (str[0] == 'P' && str[1] == 'l')
	{
		tmp = str;
		tmp += 8;
		fill->size_m[0] = (size_t)ft_atoi(tmp);
		while (*tmp != ' ')
		{
			tmp++;
		}
		tmp++;
		fill->size_m[1] = (size_t)ft_atoi(tmp);
	}
}

void		get_player(t_fill *fill, char *str)
{
	if (str[0] == '$' && str[9] == 'p')
	{
		if (str[10] == '1')
			fill->player = 1;
		else if (str[10] == '2')
			fill->player = 2;
	}
}

