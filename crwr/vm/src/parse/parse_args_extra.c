/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:30:26 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 19:39:01 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int32_t		update_dump_flag(const int32_t dump_flag)
{
	static int32_t	dump = -1;

	if (dump_flag > -1)
		dump = dump_flag;
	return (dump);
}

uint8_t		get_number_of_players(void)
{
	uint8_t	i;
	int8_t	n;

	i = 0;
	n = update_n_flag(-1);
	while (n)
	{
		n = n & (n - 1);
		i++;
	}
	return (i);
}

int8_t		update_n_flag(const int8_t shift)
{
	static int8_t	n_positions = 0;

	if (n_positions & 1 << shift)
		return (-1);
	n_positions = n_positions | 1 << shift;
	return (n_positions);
}

uint8_t		update_limit_number(uint8_t i)
{
	static uint8_t	limit = 0;

	if (i)
		limit++;
	return (limit);
}

int32_t		get_number_dump_cycle(void)
{
	return (update_dump_flag(-1));
}
