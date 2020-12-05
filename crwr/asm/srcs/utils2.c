/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "libftprintf.h"

int		go_through_spaces(char *line, int id)
{
	while (line[id] == ' ' || line[id] == '\t')
		id++;
	return (id);
}

void	exit_func(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	close_fd(int a, int b, char *filename)
{
	close(a);
	close(b);
	ft_printf("Writing output program to %s\n", filename);
}
