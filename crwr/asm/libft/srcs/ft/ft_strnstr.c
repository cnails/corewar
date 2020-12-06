/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = (size_t)ft_strlen((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len != 0 && n <= len)
	{
		if (*haystack == *needle)
			if (ft_memcmp(haystack, needle, n) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
