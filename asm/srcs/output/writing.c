/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "libftprintf.h"

int		write_header_in_file(char *str, int size, int fd, int f)
{
	int		i;

	i = 0;
	if (f == 1)
		size += 3;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	while (i < size)
	{
		ft_putchar_fd(0x0, fd);
		i++;
	}
	return (0);
}

int		get_code_op(char *name)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (name && !ft_strcmp(name, g_op_tab[i].name_oper))
			return (g_op_tab[i].opcode);
		i++;
	}
	return (-1);
}

int		put_dir_code(int args, int type, int fd, int sizeof_t_dir)
{
	int		count;
	int8_t	tmp;

	if (type == T_DIR)
		count = 4 - 2 * sizeof_t_dir;
	else if (type == T_IND)
		count = 2;
	else
		count = 1;
	while (count > 0)
	{
		tmp = (args >> ((count - 1) * CHAR_BIT)) & 0xFF;
		ft_putchar_fd(tmp, fd);
		count--;
	}
	return (args);
}

int		args_to_code(t_arg *args)
{
	int		i;
	int		code;

	i = 0;
	code = 0;
	while (i < 3)
	{
		code = code | args[i].type;
		code = code << 2;
		i++;
	}
	return (code);
}

int		count_label_size(t_data *data, t_arg *args, int cur_size, int tdir_size)
{
	int		i;
	int		count;
	t_sort	*sort;
	t_instr *all_instr;

	i = 0;
	count = 0;
	sort = NULL;
	all_instr = data->instrs;
	while (i < data->instr_num)
	{
		sort = all_instr[i].labels;
		while (sort)
		{
			if (sort->label && args->label && ft_strcmp(sort->label, \
															args->label) == 0)
			{
				count = all_instr[i].sum_size - all_instr[i].size - cur_size;
				return (count);
			}
			sort = sort->next;
		}
		i++;
	}
	return (args->value);
}
