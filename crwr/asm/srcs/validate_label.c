/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		label_validation(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && (str[i] != LABEL_CHAR))
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && LABEL_CHARS[j] != str[i])
			j++;
		if (LABEL_CHARS[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
