/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:33:44 by okres             #+#    #+#             */
/*   Updated: 2016/12/07 18:16:56 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;

	ptr = NULL;
	if (lst)
	{
		ptr = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (lst->next)
			ptr->next = ft_lstmap(lst->next, f);
		return (ptr);
	}
	return (NULL);
}
