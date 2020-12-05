/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	count_size_of_block(t_data *data)
{
	int i;
	int block_size;
	int size_of_t_dir;

	block_size = 2;
	i = 0;
	size_of_t_dir = 4;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].bit_type == 0)
		block_size--;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].tdir_size == 1)
		size_of_t_dir = 2;
	while (i < g_op_tab[data->instrs[data->instr_num].id_instr].col_args)
	{
		if (data->instrs[data->instr_num].args[i].type == T_DIR)
			block_size += size_of_t_dir;
		else if (data->instrs[data->instr_num].args[i].type == T_IND)
			block_size += 2;
		else if (data->instrs[data->instr_num].args[i].type == T_REG)
			block_size++;
		i++;
	}
	data->instrs[data->instr_num].size = block_size;
}
