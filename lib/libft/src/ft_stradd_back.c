/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_stradd_back(char *str, size_t len, char c)
{
	char	*ans;
	size_t	i;

	if (len <= (i = ft_strlen(str)))
		return (str);
	if (!(ans = ft_strnew(len)))
		return (NULL);
	if (str)
		ans = ft_strcat(ans, str);
	while (i < len)
	{
		ans[i] = c;
		i++;
	}
	free(str);
	return (ans);
}
