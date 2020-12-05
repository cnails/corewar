/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_memory_of_instr_blocks(t_data *data, int num_instr)
{
	int j;

	j = 0;
	if (data->instrs[num_instr].labels != NULL)
		sort_del(&data->instrs[num_instr].labels);
	ft_strdel(&data->instrs[num_instr].name);
	ft_strdel(&data->instrs[num_instr].label);
	while (j < 3)
	{
		ft_strdel(&data->instrs[num_instr].args[j].label);
		j++;
	}
}

void	free_two_dim_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_memory_in_main_structure(t_data *data)
{
	int i;
	int num_of_all_i;

	i = 0;
	num_of_all_i = data->instr_num;
	if (data->header != NULL)
		free(data->header);
	while (i < num_of_all_i)
	{
		free_memory_of_instr_blocks(data, i);
		i++;
	}
	ft_strdel(&data->all_labels);
	ft_strdel(&data->file);
	if (data->label != NULL)
		free(data->label);
	if (data->instrs != NULL)
		free(data->instrs);
}
