/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "libftprintf.h"

int		ft_skip(char *line, int skipped)
{
	while (line[skipped] == ' ' || line[skipped] == '\t')
		skipped++;
	return (skipped);
}

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_close_fd(int first_f, int second_f, char *filename)
{
	close(first_f);
	close(second_f);
	ft_printf("Writing output program to %s\n", filename);
}

int		get_bool(t_data *data, int i)
{
	int bool;

	bool = 0;
	if (data->instrs[data->instr_num].args[i].type == T_DIR)
		bool = T_DIR & \
				g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	else if (data->instrs[data->instr_num].args[i].type == T_IND)
		bool = T_IND & \
				g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	else if (data->instrs[data->instr_num].args[i].type == T_REG)
		bool = T_REG & \
				g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
	return (bool);
}
