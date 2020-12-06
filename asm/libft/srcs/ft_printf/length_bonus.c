/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_z(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa_signed(va_arg(ap, size_t), 10));
	if (typeflag == 'u')
		return (ft_itoabase(va_arg(ap, size_t), 10));
	else if (typeflag == 'o')
		return (ft_itoabase(va_arg(ap, size_t), 8));
	else if (typeflag == 'x')
		return (ft_itoahex(va_arg(ap, size_t), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex(va_arg(ap, size_t), 'u'));
	return (ft_strnew(1));
}

char	*length_j(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa_signed(va_arg(ap, intmax_t), 10));
	if (typeflag == 'u')
		return (ft_itoabase(va_arg(ap, intmax_t), 10));
	else if (typeflag == 'o')
		return (ft_itoabase(va_arg(ap, intmax_t), 8));
	else if (typeflag == 'x')
		return (ft_itoahex(va_arg(ap, intmax_t), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex(va_arg(ap, intmax_t), 'u'));
	return (ft_strnew(1));
}
