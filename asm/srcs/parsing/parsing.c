/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parse_line(char *str, t_data *data)
{
	if (check_is_a_comment(str) == 1)
		return (-1);
	if (data->header->is_comment == 0 || data->header->is_name == 0)
		parsing_of_header(data->header, str, data->line_count);
	else if (data->header->is_comment == 1 && data->header->is_name == 1)
		parsing_of_body(str, data);
	return (1);
}

void	read_whole_file(t_data *data)
{
	char	*string;

	while (get_next_line(data->read_fd, &string))
	{
		data->line_count++;
		parse_line(string, data);
		ft_strdel(&string);
	}
	ft_strdel(&string);
}

int		check_is_a_comment(char *string)
{
	int i;

	i = 0;
	while ((string[i] == ' ' || string[i] == '\t') && string[i] != '\0')
	{
		i++;
	}
	if (string[i] == COMMENT_CHAR \
	|| string[i] == ALT_COMMENT_CHAR || string[i] == '\0')
		return (1);
	return (0);
}
