/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parsing_ind(char *argument, t_data *data, int n)
{
	int chislo;

	if (ft_isdigit(argument[0]) || argument[0] == '+' || argument[0] == '-')
	{
		data->instrs[data->instr_num].args[n].type = T_IND;
		if (validate_number(argument))
		{
			chislo = ft_atoi(argument);
			data->instrs[data->instr_num].args[n].value = chislo;
		}
		else
			free_memory_and_write_error(LOL, data->split, data, (*data->symbol_number));
	}
	else if (argument[0] == LABEL_CHAR)
	{
		if (ft_strstr(data->all_labels, &argument[1]) != 0)
		{
			data->instrs[data->instr_num].args[n].type = T_IND;
			data->instrs[data->instr_num].args[n].label = \
															ft_strdup(&argument[1]);
		}
		else
			free_memory_and_write_error("No such label", \
                    data->split, data, (*data->symbol_number));
	}
}

void		parsing_dir(char *argument, t_data *data, int n)
{
	if (ft_strchr(argument, DIRECT_CHAR))
	{
		data->instrs[data->instr_num].args[n].type = T_DIR;
		if (ft_strchr(argument, LABEL_CHAR))
		{
			if (!argument[0] || !argument[1] || !argument[2])
				free_memory_and_write_error("Invalid direct argument with label", \
                                    data->split, data, (*data->symbol_number));
			if (argument[0] == DIRECT_CHAR && argument[1] == LABEL_CHAR)
			{
				if (ft_strstr(data->all_labels, &argument[2]) != 0)
					data->instrs[data->instr_num].args[n].label = \
															ft_strdup(&argument[2]);
				else
					free_memory_and_write_error("No such label",
												data->split, data, (*data->symbol_number));
			}
			else
				free_memory_and_write_error("Invalid direct argument with label", \
                                    data->split, data, (*data->symbol_number));
		}
		else
			get_number(argument, data, n);
	}
}

void		parsing_r(char *argument, t_data *data, int n)
{
	int chislo;

	if (argument[0] == 'r' && argument[1] && ft_isdigit(argument[1]))
	{
		data->instrs[data->instr_num].args[n].type = T_REG;
		chislo = ft_atoi(&argument[1]);
		if (!validate_number(&argument[1]) || (chislo < 1 || chislo > 16))
			free_memory_and_write_error("Invalid register in args", data->split, \
                                                data, (*data->symbol_number));
		data->instrs[data->instr_num].args[n].value = chislo;
	}
}

void		parsing_of_one_argument(char *old_arg, t_data *data, int n)
{
	char *argument;

	argument = ft_strtrim(old_arg);
	parsing_r(argument, data, n);
	if (data->instrs[data->instr_num].args[n].type == 0)
		parsing_dir(argument, data, n);
	if (data->instrs[data->instr_num].args[n].type == 0)
		parsing_ind(argument, data, n);
	ft_strdel(&argument);
	if (data->instrs[data->instr_num].args[n].type == 0)
		free_memory_and_write_error("Invalid type of argument", data->split, data, \
                                                        (*data->symbol_number));
	data->instrs[data->instr_num].args[n].arg_number = n;
}

void		parse_all_arguments(char *split, int *i, t_data *data)
{
	char	**all_arguments;
	int		num_of_args;
	int		j;

	j = 0;
	all_arguments = ft_strsplit(&split[*i], SEPARATOR_CHAR);
	num_of_args = length_of_massiv(all_arguments);
	if (num_of_args > 3 || all_arguments == NULL)
		free_memory_and_write_error(FT_PARSE_ARGS1, split, data, *i);
	if (all_arguments == NULL)
		free_memory_and_write_error(FT_PARSE_ARGS2, split, data, *i);
	while (all_arguments[j] && j < num_of_args)
	{
		parsing_of_one_argument(all_arguments[j], data, j);
		j++;
	}
	j = check_args(data);
	if (j == TOO_MANY_ARGS)
		free_memory_and_write_error("Invalid number of all_arguments(too many)", split, \
                                                                    data, *i);
	else if (j == FEW_ARGS)
		free_memory_and_write_error("Invalid number of all_arguments(few)", split, data, *i);
	else if (j == INVALID_TYPE)
		free_memory_and_write_error("Invalid type of all_arguments", split, data, *i);
	free_two_dim_array(all_arguments);
}
