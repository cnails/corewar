/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../libft/includes/libftprintf.h"

char		*parsing_of_label(char *arr, int *sym_num)
{
	char	**all_labels;
	char	*one_label;

	eliminate_spaces(arr, sym_num);
	all_labels = ft_strsplit(&arr[*sym_num], LABEL_CHAR);
	if (all_labels != NULL)
	{
		if (label_validation(all_labels[0]))
		{
			(*sym_num) += ft_strlen(all_labels[0]);
			if (arr[*sym_num] && arr[*sym_num] == ':')
			{
				(*sym_num)++;
				one_label = ft_strdup(all_labels[0]);
				free_two_dim_array(all_labels);
				return (one_label);
			}
		}
	}
	free_two_dim_array(all_labels);
	return (NULL);
}
