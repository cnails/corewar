/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
