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
	t_data	d;

	if (ac == 1)
		exit_func(USAGE);
	validate_filename(av[ac - 1]);
	if ((d.read_fd = open(av[ac - 1], O_RDONLY)) < 3)
	{
		close(d.read_fd);
		exit_func("Bad file read\n");
	}
	if (read(d.read_fd, NULL, 0) < 0)
	{
		close(d.read_fd);
		exit_func("Bad file read\n");
	}
	initialization_function(&d, count_number_lines(&d, -1));
	lseek(d.read_fd, 0, 0);
	read_whole_file(&d);
	ft_cor_extension(av[ac - 1], &d);
	if ((d.write_fd = open(d.file, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		exit_func("Unable to create .cor file\n");
	put_something_to_file(&d, d.write_fd);
	close_fd(d.read_fd, d.write_fd, d.file);
	free_mem_inst(&d);
	return (0);
}
