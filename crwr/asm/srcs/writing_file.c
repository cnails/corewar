/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_file_size(t_data *data)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	data->instrs[0].get_file_size = 0;
	while (i < data->instr_num)
	{
		sum = data->instrs[i].size + sum;
		data->instrs[i].get_file_size = sum;
		i++;
	}
	data->file_size = sum;
}

void	write_hex(long num, int fd)
{
	if (num >= 256)
	{
		write_hex(num / 256, fd);
		write_hex(num % 256, fd);
	}
	else
		ft_putchar_fd(num, fd);
}

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

int		writing_in_file(t_data *data, int fd)
{
	get_file_size(data);
	write_exec_to_fd(COREWAR_EXEC_MAGIC, fd);
	write_header_in_file(data->header->prog_name, PROG_NAME_LENGTH + 1, fd, 0);
	write_size_fd(data->file_size, fd);
	write_header_in_file(data->header->comment, COMMENT_LENGTH + 1, fd, 1);
	write_instr_to_fd(data, fd);
	return (0);
}
