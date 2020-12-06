/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(int n)
{
	int	count;
	int buf;

	buf = n;
	count = 0;
	if (n <= 0)
	{
		buf *= -1;
		count++;
	}
	while (buf > 0)
	{
		buf /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*str_n;
	int		count;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	count = ft_count_digits(n);
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
		str_n[i--] = n % 10 + 48;
		n /= 10;
	}
	return (str_n);
}
