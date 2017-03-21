#include "filler.h"

int		distance(int x, int y, int x1, int y1)
{
	int	res;
	int	res1;

	res = (x - x1);
	res1 = (y - y1);
	if (res < 0)
		res = -res;
	if (res1 < 0)
		res1 = -res1;
	return (res + res1);
}

t_point			find_player(char **str, char c, t_fill *fill)
{
	int i;
	int j;
	t_point p;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == fill->player && (str[i][j - 1] == '.'
											  || str[i][j + 1] == '.' ||
											  str[i - 1][j] == '.' || str[i + 1][j] == '.'))
			{
				p.x = j;
				p.y = i;
			}

			j++;
		}
		i++;
	}
	free(str);
}