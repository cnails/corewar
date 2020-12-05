/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		ft_exit(USAGE);
	validate_filename(av[ac - 1]);
	if ((data.read_fd = open(av[ac - 1], O_RDONLY)) < 3)
	{
		close(data.read_fd);
		ft_exit("Bad file read\n");
	}
	if (read(data.read_fd, NULL, 0) < 0)
	{
		close(data.read_fd);
		ft_exit("Bad file read\n");
	}
	initialization_function(&data, lines_num(&data, -1));
	lseek(data.read_fd, 0, 0);
	read_whole_file(&data);
	ft_cor_extension(av[ac - 1], &data);
	if ((data.write_fd = open(data.file, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		ft_exit("Unable to create .cor file\n");
	writing_to_file(&data, data.write_fd);
	ft_close_fd(data.read_fd, data.write_fd, data.file);
	free_memory_in_main_structure(&data);
	return (0);
}
