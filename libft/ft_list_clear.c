/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:16:59 by okres             #+#    #+#             */
/*   Updated: 2016/12/10 14:17:01 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *list;

	list = *begin_list;
	while (list)
	{
		if (list->next)
		{
			tmp = list->next;
		}
		else
			tmp = 0;
		free(list);
		list = tmp;
	}
}
