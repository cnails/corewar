/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtypes_ubp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_u(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)10));
}

char	*ft_b(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)2));
}

char	*ft_p(va_list ap)
{
	char *str;

	str = ft_itoahex((unsigned long long)va_arg(ap, void *), 'l');
	str = ft_stradd_front(str, ft_strlen(str) + 2, '0');
	str[1] = 'x';
	return (str);
}
