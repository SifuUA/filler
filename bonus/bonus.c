#include "filler.h"

void	get_color(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'X')
			ft_putstr(YELLOW"X"RESET);
		else if (str[i] == 'x')
			ft_putstr(GREEN"x"RESET);
		else if (str[i] == 'O')
			ft_putstr(BLUE"O"RESET);
		else if (str[i] == 'o')
			ft_putstr(MAGENTA"o"RESET);
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putstr("\n");
}

char	**creat_ar()
{
	char	**ar;

	ar = (char **)malloc(sizeof(char *) * 11);
	if (!ar)
		exit(1);
	return (ar);
}

char	**write_up()
{
	char	*str;
	char	**ar;
	int 	i;

	i = 0;
	ar = creat_ar();
	while (get_next_line(0, &str) && i < 9)
	{
		ar[i] = ft_strdup(str);
		i++;
		free(str);
	}
	return (ar);
}

void	write_field(char **line)
{
	char *str;

	while (get_next_line(0, &str) > 0)
	{
		if (*str == 'P' && str[1] == 'l')
		{
			nanosleep((const struct timespec[]){{0, 25990000}}, NULL);
			ft_putstr(CLEAR);
			ft_putstr(RETUR);
			ft_putstr(MAGENTA);
			ft_arr_putstr(line);
			ft_putstr(RESET);
		}
		if (*str != 'P' && *str != '<')
			get_color(str);
		else
		{
			ft_putstr(str);
			ft_putstr("\n");
		}
		free(str);
	}

}

int 	main(int argc, char **argv)
{

	char **up;

	up = write_up();
	write_field(up);
}