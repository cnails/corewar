/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "../libft/includes/libftprintf.h"

void	error_function_for_body(char *error_name, char *str, int n, int column)
{
	ft_putstr_fd(error_name, 2);
	ft_putstr_fd(", [", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(column, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd(", line:'", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("'", 2);
	exit(1);
}

void	length_og_error(int f)
{
	if (f == 0)
	{
		ft_putstr_fd("Champion name too long (Max length ", 2);
		ft_putnbr_fd(PROG_NAME_LENGTH, 2);
		ft_putendl_fd(")", 2);
	}
	else if (f == 1)
	{
		ft_putstr_fd("Champion comment too long (Max length ", 2);
		ft_putnbr_fd(COMMENT_LENGTH, 2);
		ft_putendl_fd(")", 2);
	}
	exit(1);
}

void	free_memory_and_write_error(char *err, char *line, t_data *data, int ind_str)
{
	int line_count;

	line_count = data->line_count;
	free_memory_in_main_structure(data);
	error_function_for_body(err, line, line_count, ind_str);
}

void	error_function(char *name_error, char *string, int n, int column)
{
	int		i;

	i = 0;
	ft_putstr_fd(name_error, 2);
	ft_putstr_fd(" [", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(column, 2);
	ft_putstr_fd("]", 2);
	if (string)
	{
		write(2, " INSTRUCTION \"", 14);
		while (string[i] != ' ' && string[i] != '\t' && string[i] != COMMENT_CHAR && \
							string[i] != ALT_COMMENT_CHAR && string[i] != '\0')
		{
			ft_putchar_fd(string[i], 2);
			i++;
		}
		write(2, "\"\n", 2);
	}
	else
		write(2, "\n", 1);
	exit(1);
}
