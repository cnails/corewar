/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		valid_args(t_data *data)
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
		if (!get_bool(data, i))
			return (INVALID_TYPE);
		i++;
	}
	return (1);
}
