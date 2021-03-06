/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		extract_bool_val(t_data *data, int i)
{
	int val;

	val = 0;
	if (data->instrs[data->instr_num].args[i].type == T_DIR)
		val = T_DIR & \
				g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	else if (data->instrs[data->instr_num].args[i].type == T_IND)
		val = T_IND & \
				g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	else if (data->instrs[data->instr_num].args[i].type == T_REG)
		val = T_REG & \
				g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	return (val);
}

int		check_args(t_data *data)
{
	int i;
	int num_args;

	i = 0;
	num_args = g_op_tab[data->instrs[data->instr_num].id_instr].col_args;
	while (i < 3)
	{
		if ((num_args) == i)
		{
			if (i < 3 && data->instrs[data->instr_num].args[i].type != 0)
				return (TOO_MANY_ARGS);
			else
				return (1);
		}
		if (data->instrs[data->instr_num].args[i].type == 0)
			return (FEW_ARGS);
		if (!extract_bool_val(data, i))
			return (INVALID_TYPE);
		i++;
	}
	return (1);
}
