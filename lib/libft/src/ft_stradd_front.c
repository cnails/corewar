/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_stradd_front(char *str, size_t len, char c)
{
	char	*ans;
	size_t	len_str;

	if (len <= (len_str = ft_strlen(str)))
		return (str);
	if (!(ans = ft_strnew(len)))
		return (NULL);
	ans = ft_memset(ans, c, len - len_str);
	if (str)
		ans = ft_strcat(ans, str);
	free(str);
	return (ans);
}
