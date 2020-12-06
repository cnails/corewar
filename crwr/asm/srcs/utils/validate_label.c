/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		label_validation(char *label)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (label[i] && (label[i] != LABEL_CHAR))
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && LABEL_CHARS[j] != label[i])
			j++;
		if (LABEL_CHARS[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
