/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_number(char *argument, t_data *data, int n)
{
	int chislo;

	if (argument[0] != DIRECT_CHAR)
		free_memory_and_write_error("Invalid direct argument without label", \
                                    data->split, data, (*data->symbol_number));
	chislo = ft_atoi(&argument[1]);
	if (!validate_number(&argument[1]))
		free_memory_and_write_error("Invalid direct argument without label", \
                                    data->split, data, (*data->symbol_number));
	data->instrs[data->instr_num].args[n].value = chislo;
}

void	eliminate_all_comments(char *initial_string, char **string)
{
	char **all_strings;

	if (ft_strchr(initial_string, COMMENT_CHAR))
	{
		all_strings = ft_strsplit(initial_string, COMMENT_CHAR);
		*string = ft_strdup(all_strings[0]);
		free_two_dim_array(all_strings);
	}
	else if (ft_strchr(initial_string, ALT_COMMENT_CHAR))
	{
		all_strings = ft_strsplit(initial_string, ALT_COMMENT_CHAR);
		*string = ft_strdup(all_strings[0]);
		free_two_dim_array(all_strings);
	}
	else
		*string = ft_strdup(initial_string);
}

void	go_to_start_if_label_in_arg(char *string, int *sym_num, t_data *data)
{
	if (*sym_num != 0 && data->instrs[data->instr_num].label == NULL)
	{
		*sym_num = 0;
		eliminate_spaces(string, sym_num);
	}
}

void	initial_parsing_of_label(char *string, t_data *data, int *sym_num, \
																char **label)
{
	char	*good_label;

	if (ft_strchr(string, LABEL_CHAR))
	{
		good_label = parsing_of_label(string, sym_num);
		*label = good_label;
		if (good_label != NULL)
		{
			if (data->instrs[data->instr_num].label == NULL)
			{
				data->instrs[data->instr_num].label = good_label;
				data->instrs[data->instr_num].labels = \
													push_block(ft_strdup(good_label));
			}
			else
				push_to_the_end(good_label, &data->instrs[data->instr_num].labels);
		}
	}
}

void	parsing_of_body(char *initial_string, t_data *data)
{
	int		sym_num;
	char	*string;
	char	*good_label;

	eliminate_all_comments(initial_string, &string);
	sym_num = 0;
	data->instrs[data->instr_num].sum_size = 0;
	data->instrs[data->instr_num].id = data->instr_num;
	data->symbol_number = &sym_num;
	data->split = initial_string;
	initial_parsing_of_label(string, data, &sym_num, &good_label);
	eliminate_spaces(string, &sym_num);
	go_to_start_if_label_in_arg(string, &sym_num, data);
	if (string[sym_num] == '\0')
	{
		ft_strdel(&string);
		return ;
	}
	parsing_function(string, &sym_num, data);
	parse_all_arguments(string, &sym_num, data);
	count_size_of_block(data);
	data->instr_num += 1;
	ft_strdel(&string);
}
