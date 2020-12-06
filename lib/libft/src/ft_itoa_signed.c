/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int		ft_count_digits(long long n, unsigned int base)
{
	int			count;
	long long	buf;

	count = 0;
	buf = n;
	if (n <= 0)
	{
		buf *= -1;
		count++;
	}
	while (buf > 0)
	{
		buf /= base;
		count++;
	}
	return (count);
}

char			*ft_itoa_signed(long long n, unsigned int base)
{
	char	*str_n;
	int		count;
	size_t	i;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	count = ft_count_digits(n, base);
	str_n = ft_strnew(count);
	if (!str_n)
		return (NULL);
	if (n < 0)
	{
		str_n[0] = '-';
		n *= -1;
	}
	i = count - 1;
	if (n == 0)
		str_n[i] = 0 + 48;
	while (n > 0)
	{
		str_n[i--] = n % base + 48;
		n /= base;
	}
	return (str_n);
}
