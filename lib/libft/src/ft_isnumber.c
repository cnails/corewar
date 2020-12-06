/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 22:17:39 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function checks for a number in a string
** (may contain one sign at the start and digits).
**
** Функция проверяет, является ли строка числом
** (может содержать один знак вначале и цифры).
*/

int				ft_isnumber(const char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (i == 0)
			{
				i++;
				if (str[i])
					continue;
				else
					return (0);
			}
			else
				return (0);
		}
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
