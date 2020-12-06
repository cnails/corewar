/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char		*ft_revstr(char *str)
{
	size_t	i;
	size_t	len;
	char	buf;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		buf = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buf;
		i++;
	}
	return (str);
}
