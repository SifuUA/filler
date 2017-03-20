/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:17:58 by okres             #+#    #+#             */
/*   Updated: 2016/12/10 14:18:05 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ptr;
	char			*res;
	size_t			len;
	unsigned int	start;

	if (!s)
		return (NULL);
	len = 0;
	start = 0;
	res = (char *)s;
	ptr = (char *)s;
	while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')
	{
		ptr++;
		start++;
	}
	if (start == ft_strlen(s))
		return (ft_strdup(""));
	res = res + (ft_strlen(s) - 1);
	while (*res == ' ' || *res == '\n' || *res == '\t')
		res--;
	len = res - ptr + 1;
	return (ft_strsub(s, start, len));
}
