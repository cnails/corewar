/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strcat_front(char *dest, const char *src,
		size_t len_buf, size_t len2)
{
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	if (!dest || !src)
		return (NULL);
	while (k != len2)
	{
		k = len_buf - i;
		dest[k] = dest[len_buf - len2 - i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
