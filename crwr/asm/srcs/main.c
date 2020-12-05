/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		exit_func(USAGE);
	validate_filename(av[ac - 1]);
	if ((data.read_fd = open(av[ac - 1], O_RDONLY)) < 3)
	{
		close(data.read_fd);
		exit_func("Bad file read\n");
	}
	if (read(data.read_fd, NULL, 0) < 0)
	{
		close(data.read_fd);
		exit_func("Bad file read\n");
	}
	initialization_function(&data, count_number_lines(&data, -1));
	lseek(data.read_fd, 0, 0);
	read_whole_file(&data);
	ft_cor_extension(av[ac - 1], &data);
	if ((data.write_fd = open(data.file, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		exit_func("Unable to create .cor file\n");
	put_something_to_file(&data, data.write_fd);
	close_fd(data.read_fd, data.write_fd, data.file);
	free_memory_in_main_structure(&data);
	return (0);
}
