/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:20:48 by okres             #+#    #+#             */
/*   Updated: 2017/01/13 13:39:11 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*create(char *buff, int fd)
{
	t_gnl *ptr;

	ptr = (t_gnl *)malloc(sizeof(t_gnl));
	if (!ptr)
		return (NULL);
	if (!buff)
	{
		ptr->buff = NULL;
		fd = 0;
	}
	else
	{
		ptr->buff = buff;
		ptr->fd = fd;
		ptr->next = NULL;
	}
	return (ptr);
}

void		read_in_buffer(const int fd, char **buffer, int *read_return)
{
	char	tmp[BUFF_SIZE + 1];
	char	*p;

	ft_bzero(tmp, BUFF_SIZE + 1);
	*read_return = read(fd, tmp, BUFF_SIZE);
	if (*read_return == 0)
		return ;
	tmp[*read_return] = '\0';
	p = ft_strjoin(*buffer, tmp);
	ft_strdel(buffer);
	*buffer = p;
}

void		chek_and_add_node(t_gnl **begin, t_gnl **p, t_gnl **p1, int fd)
{
	int		flag;

	flag = 0;
	if (*begin == NULL)
	{
		*begin = create(ft_strnew(0), fd);
		*p = *begin;
	}
	else
	{
		while (*p)
		{
			if ((*p1 = *p) && (*p)->fd == fd)
			{
				flag = 1;
				break ;
			}
			*p = (*p1)->next;
		}
		if (flag == 0)
		{
			(*p1)->next = create(ft_strnew(0), fd);
			*p = (*p1)->next;
		}
	}
}

int			end(int *read_return, char **buff, char **line)
{
	if (*read_return == 0 && *buff && **buff != '\0')
	{
		*line = ft_strdup(*buff);
		ft_strdel(&(*buff));
		return (1);
	}
	else if (*line)
		*line = ft_strnew(0);
	return (*read_return);
}

int			get_next_line(const int fd, char **line)
{
	static		t_gnl	*begin;
	t_gnl				*p;
	t_gnl				*p1;
	char				*ptr;
	int					read_return;

	if (fd < 0 || BUFF_SIZE > 65534 || !line)
		return (-1);
	p = begin;
	chek_and_add_node(&begin, &p, &p1, fd);
	read_return = 1;
	while (read_return > 0)
	{
		read_in_buffer(fd, &(p->buff), &read_return);
		if (p->buff && ((ptr = ft_strchr(p->buff, '\n')) != NULL))
		{
			*ptr = '\0';
			*line = ft_strdup(p->buff);
			ft_memmove(p->buff, ptr + 1, ft_strlen(ptr + 1) + 1);
			if (ft_strlen(*line) > 0 || **line == '\0')
				return (1);
		}
	}
	return (end(&read_return, &(p->buff), &(*line)));
}
