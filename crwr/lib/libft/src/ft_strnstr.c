/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
