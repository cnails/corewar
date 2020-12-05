/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_filename(char *filename)
{
	if (ft_strlen(ft_strstr(filename, ".s")) != 2)
		ft_exit("Bad file filename\n");
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

