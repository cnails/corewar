/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	initialization_function(t_data *data, int n)
{
	if (!(data->header = (t_header*)malloc(sizeof(t_header))))
		exit_func(MALLOC_ERR);
	ft_memset(data->header->prog_name, '\0', PROG_NAME_LENGTH + 1);
	ft_memset(data->header->comment, '\0', COMMENT_LENGTH + 1);
	data->header->is_comment = 0;
	data->header->is_name = 0;
	if (!(data->instrs = (t_instr*)malloc(sizeof(t_instr) * n)))
		exit_func(MALLOC_ERR);
	ft_memset(data->instrs, '\0', sizeof(t_instr) * n);
	if (!(data->label = (t_label*)malloc(sizeof(t_label))))
		exit_func(MALLOC_ERR);
	data->line_count = 0;
	data->instr_num = 0;
}
