/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_size_fd(long num, int fd)
{
	long	to_hex;
	size_t	count;

	to_hex = num;
	count = 0;
	while (num != 0)
	{
		num /= 256;
		count++;
	}
	while (7 - count != 0)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	write_hex(to_hex, fd);
}

void	write_args_to_fd(t_data *data, int ind_instr, int code_op, int fd)
{
	int		i;
	int		size;
	t_arg	*args;
	t_instr *instrs;

	i = 0;
	instrs = &data->instrs[ind_instr];
	args = data->instrs[ind_instr].args;
	while (i < g_op_tab[code_op - 1].col_args)
	{
		if (args[i].type == T_REG)
			ft_putchar_fd(args[i].value, fd);
		else
		{
			size = size_to_label(data, &args[i], instrs->get_file_size \
							- instrs->size, g_op_tab[code_op - 1].tdir_size);
			write_code_dir(size, args[i].type, fd, \
											g_op_tab[code_op - 1].tdir_size);
		}
		i++;
	}
}

void	write_instr_to_fd(t_data *data, int fd)
{
	int		i;
	int		code_op;

	i = 0;
	while (i < data->instr_num)
	{
		code_op = code_operation(data->instrs[i].name);
		ft_putchar_fd(code_op, fd);
		if (g_op_tab[code_op - 1].bit_type == 1)
			ft_putchar_fd(code_args(data->instrs[i].args), fd);
		write_args_to_fd(data, i, code_op, fd);
		i++;
	}
}

void	write_exec_to_fd(long num, int fd)
{
	int		count;

	count = 0;
	while (num != 0)
	{
		num /= 256;
		count++;
	}
	while (4 - count != 0)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	write_hex(COREWAR_EXEC_MAGIC, fd);
}
