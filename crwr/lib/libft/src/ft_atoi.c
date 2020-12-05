/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int		ft_atoi(const char *src)
{
	unsigned char			*str;
	int						flag;
	unsigned long long		result;

	flag = 1;
	result = 0;
	str = (unsigned char*)src;
	while (*str == ' ' || *str == '\t' || *str == '\v' \
		|| *str == '\r' || *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		flag = *str == '-' ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (result > 9223372036854775807)
		return (flag > 0 ? -1 : 0);
	else
		return (((int)(flag * result)));
}
