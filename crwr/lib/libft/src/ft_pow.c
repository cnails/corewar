/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_pow(int x, unsigned int n)
{
	size_t	result;
	size_t	check;

	result = 1;
	while (n)
	{
		check = result;
		if (n & 1)
			result = result * (long double)x;
		x *= x;
		n = n >> 1;
		if (result < check)
			ft_printf("ERROR: overflow error\n");
	}
	return ((size_t)result);
}
