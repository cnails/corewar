/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
