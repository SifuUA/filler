/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:17:12 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:49:11 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	size_t	index;
	t_list	*node;

	if (begin_list == 0)
		return (0);
	index = 0;
	node = begin_list;
	while (node->next != 0)
	{
		node = node->next;
		index++;
	}
	return (index);
}
