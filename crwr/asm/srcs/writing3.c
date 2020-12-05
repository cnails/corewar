/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_magic_to_fd(long nb, int fd)
{
	int		size;
	int		count;

	size = nb;
	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (7 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	put_to_fd(size, fd);
}

int		put_something_to_file(t_data *data, int fd)
{
	count_sum_size(data);
	magic_number_put_fd(COREWAR_EXEC_MAGIC, fd);
	write_header_in_file(data->header->prog_name, PROG_NAME_LENGTH + 1, fd, 0);
	put_magic_to_fd(data->file_size, fd);
	write_header_in_file(data->header->comment, COMMENT_LENGTH + 1, fd, 1);
	instrsToFd(data, fd);
	return (0);
}

void	wput_args_to_fd(t_data *data, int ind_instr, int code_op, int fd)
{
	int		i;
	int		size;
	t_arg	*args;
	t_instr *instrs;

	i = 0;
	size = 0;
	instrs = &data->instrs[ind_instr];
	args = data->instrs[ind_instr].args;
	while (i < g_op_tab[code_op - 1].col_args)
	{
		if (args[i].type == T_REG)
			ft_putchar_fd(args[i].value, fd);
		else
		{
			size = count_label_size(data, &args[i], instrs->sum_size \
 - instrs->size, g_op_tab[code_op - 1].tdir_size);
			put_dir_code(size, args[i].type, fd, \
                                            g_op_tab[code_op - 1].tdir_size);
		}
		i++;
	}
}

void	instrsToFd(t_data *data, int fd)
{
	int		i;
	int		code_op;

	i = 0;
	code_op = 0;
	while (i < data->instr_num)
	{
		code_op = get_code_op(data->instrs[i].name);
		ft_putchar_fd(code_op, fd);
		if (g_op_tab[code_op - 1].bit_type == 1)
			ft_putchar_fd(args_to_code(data->instrs[i].args), fd);
		wput_args_to_fd(data, i, code_op, fd);
		i++;
	}
}
