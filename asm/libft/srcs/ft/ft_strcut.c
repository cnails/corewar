/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char *dest, size_t len_res)
{
	size_t	i;
	char	*ans;

	i = 0;
	if (len_res == ft_strlen(dest))
		return (dest);
	if (!dest || !(ans = ft_strnew(len_res)))
		return (NULL);
	while (i < len_res)
	{
		ans[i] = dest[i];
		i++;
	}
	ans[i] = '\0';
	free(dest);
	return (ans);
}
