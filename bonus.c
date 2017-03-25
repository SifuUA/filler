#include "filler.h"

char	**creat_ar()
{
	char	**ar;

	i = 0;
	ar = (chra **)malloc(sizeof(char *) * 11);
	if (!ar)
		exit(1);
	return (ar);
}

void	write_in()
{
	char	*op;
	char	**ar;
	int 	i;

	i = 0;
	arr = creat_ar();
	op = ft_strnew(1000);
	while (get_next_line(0, &op))
	{
		if (i < 9)
		{
			ar[i] = ft_strdup(op);
			i++;
		}
	}
}

int 	main(int argc, char **argv)
{

	if (argc > 1)
	{
		write_in();
	}
}
