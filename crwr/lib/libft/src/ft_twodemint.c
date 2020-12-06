/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodemint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int			**ft_twodemint(size_t strlen, size_t maslen)
{
	int		**mas;
	size_t	i;

	mas = (int**)ft_memalloc(sizeof(int*) * maslen);
	if (mas == NULL)
		return (NULL);
	i = 0;
	while (i < maslen)
	{
		mas[i] = (int*)ft_memalloc(sizeof(int) * strlen);
		if (*mas == NULL)
			return ((int**)ft_free((void**)mas, i));
		i++;
	}
	return (mas);
}
