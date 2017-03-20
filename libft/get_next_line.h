/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:22:14 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:48:48 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5
# include "libft.h"

typedef	struct		s_gnl
{
	struct s_gnl	*next;
	char			*buff;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
