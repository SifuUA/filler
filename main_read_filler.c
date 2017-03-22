#include "filler.h"
#include <fcntl.h>

/*int	main(void)
{
	int fd;
	char *buf;

	fd = open("from_filler.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	while (get_next_line(0, &buf) > 0)
	{
		ft_putendl_fd(buf, fd);
		ft_strdel(&buf);
	}
	close(fd);
	return (0);
}*/
