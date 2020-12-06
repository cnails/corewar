/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/libft.h"

static char	*my_strncat(char *dest, const char *src, size_t n, size_t len)
{
	char	*buf;

	buf = dest;
	buf = buf + len;
	while (*src && n--)
	{
		*buf++ = *src++;
	}
	*buf = 0;
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_1;
	size_t	len_2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	new_str = (char*)ft_memalloc(len_1 + len_2 + 1);
	if (new_str == NULL)
		return (NULL);
	new_str = my_strncat(new_str, s1, len_1, 0);
	new_str = my_strncat(new_str, s2, len_2, len_1);
	return (new_str);
}
