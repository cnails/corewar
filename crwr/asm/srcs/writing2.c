/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	count_sum_size(t_data *data)
{
	int		j;
	int		whole;

	j = 0;
	whole = 0;
	data->instrs[0].sum_size = 0;
	while (j < data->instr_num)
	{
		whole = data->instrs[j].size + whole;
		data->instrs[j].sum_size = whole;
		j++;
	}
	data->file_size = whole;
}

void	put_to_fd(long nbr, int fd)
{
	if (nbr >= 256)
	{
		put_to_fd(nbr / 256, fd);
		put_to_fd(nbr % 256, fd);
	}
	else
		ft_putchar_fd(nbr, fd);
}

void	magic_number_put_fd(long nb, int fd)
{
	int		count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (4 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	put_to_fd(COREWAR_EXEC_MAGIC, fd);
}
