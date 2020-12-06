/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar(0 + 48);
	else
	{
		if (n == -2147483648)
		{
			ft_putchar('-');
			ft_putchar(2 + 48);
			n = 147483648;
		}
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n / 10 == 0)
			ft_putchar(n + 48);
		else
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + 48);
		}
	}
}
