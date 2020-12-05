/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			func_validation(char *func, t_data *data)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (func && g_op_tab[i].name_oper && \
									ft_strcmp(func, g_op_tab[i].name_oper) == 0)
		{
			data->instrs[data->instr_num].id_instr = i;
			return (1);
		}
		i++;
	}
	return (0);
}

char		*spl_extr_func(char *arr, char char_split, \
																t_data *data)
{
	char	**func;
	char	*name_str;

	func = NULL;
	if (arr[0])
		func = ft_strsplit(arr, char_split);
	if (func != NULL && func[0] != NULL && \
	func_validation(func[0], data))
	{
		name_str = ft_strtrim(func[0]);
		free_two_dim_array(func);
		return (name_str);
	}
	if (func != NULL)
		free_two_dim_array(func);
	return (NULL);
}

char		*ext_name_of_fun(char *array_of_strings, int *sym_num, t_data *data)
{
	char	*func_name;

	eliminate_spaces(array_of_strings, sym_num);
	func_name = spl_extr_func(&array_of_strings[*sym_num], ' ', data);
	if (func_name == NULL)
		func_name = spl_extr_func(&array_of_strings[*sym_num], '\t', data);
	if (func_name == NULL && ft_strchr(array_of_strings, DIRECT_CHAR))
		func_name = spl_extr_func(&array_of_strings[*sym_num],
							DIRECT_CHAR, data);
	return (func_name);
}

void		parsing_function(char *split, int *i, t_data *data)
{
	char	*name;

	name = ext_name_of_fun(split, i, data);
	if (name != NULL)
	{
		data->instrs[data->instr_num].name = name;
		(*i) += ft_strlen(name);
	}
	else
		fr_mem_in("Invalid function name", split, data, *i);
}
