/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ans;
	int		i;

	i = 0;
	if (!s || !f || !(ft_strlen((char *)s) + 1))
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!ans)
		return (NULL);
	while (*s)
	{
		ans[i] = (*f)(*s);
		s++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
