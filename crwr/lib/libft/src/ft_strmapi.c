/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ans;
	unsigned int	i;

	i = 0;
	if (!s || !f || !(ft_strlen((char *)s) + 1))
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!ans)
		return (NULL);
	while (*s)
	{
		ans[i] = (*f)(i, *s);
		s++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
