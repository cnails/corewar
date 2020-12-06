/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
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

void			error_sync(char *string, int ind, int line_num)
{
	while (string[ind] != COMMENT_CHAR && \
			string[ind] != ALT_COMMENT_CHAR && string[ind] != '\0')
	{
		if (string[ind] != ' ' && string[ind] != '\t')
			error_function(SYN_ERR, (string + ind), line_num, ind + 1);
		ind++;
	}
}

int				quotes_validation(char *string, int ind, int line_num)
{
	int		i;
	int		quotes_num;
	int		num_start;

	i = ind;
	quotes_num = 0;
	num_start = -1;
	while (string[i] == ' ' || string[i] == '\t')
		i++;
	if (string[i] == '"')
	{
		quotes_num++;
		i++;
		num_start = i;
		while (string[i] != '"' && string[i] != '\0')
			i++;
		string[i] == '"' ? quotes_num++ : 0;
		i++;
		if (quotes_num != 2)
			error_function(LEX_ERR, NULL, line_num, ind + 1);
	}
	else
		error_function(SYN_ERR, (string + i), line_num, i + 1);
	error_sync(string, i, line_num);
	return (num_start);
}

static size_t	le_ch(const char *str, char ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != ch && str[i] != '\0')
		i++;
	return (i);
}

int				par_head_li(char *string, char *def, int i, int num_line)
{
	int		j;

	j = quotes_validation(string, i, num_line);
	if (j != -1)
		return (j);
	return (-1);
}

int				parsing_of_header(t_header *main, char *string, int line_num)
{
	int		id;
	int		s;

	id = 0;
	id = go_through_spaces(string, id);
	if (!main->is_name && !ft_strncmp((string + id), N_CMD_STR, (LEN_N - 1)))
	{
		s = par_head_li(string, N_CMD_STR, (id + LEN_N), line_num);
		if (le_ch((string + s), '"') > PROG_NAME_LENGTH)
			length_og_error(0);
		ft_strncpy(main->prog_name, (string + s), le_ch((string + s), '"'));
		main->is_name = 1;
	}
	else if (!main->is_comment && !ft_strncmp((string + id),
										C_CMD_STR, LEN_C - 1))
	{
		s = par_head_li(string, C_CMD_STR, (id + LEN_C), line_num);
		if (le_ch((string + s), '"') > COMMENT_LENGTH)
			length_og_error(1);
		ft_strncpy(main->comment, (string + s), le_ch((string + s), '"'));
		main->is_comment = 1;
	}
	else
		error_function(LEX_ERR, NULL, line_num, id + 1);
	return (0);
}
