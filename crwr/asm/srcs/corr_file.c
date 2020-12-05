/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:15 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_filename(char *filename)
{
	if (ft_strlen(ft_strstr(filename, ".s")) != 2)
		exit_func("Bad file filename\n");
}

void	ft_cor_extension(char *filename, t_data *data)
{
	char	*file_name;

	file_name = ft_strsub(filename, 0, ft_strlen(filename) - 2);
	filename = ft_strjoin(file_name, ".cor");
	ft_strdel(&file_name);
	data->file = ft_strdup(filename);
	ft_strdel(&filename);
}
