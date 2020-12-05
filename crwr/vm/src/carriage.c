/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:30:26 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 20:34:59 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_carriage(t_carriage *carriage, uint8_t *arena, uint8_t id)
{
	carriage->opcode = *(arena + carriage->program_counter);
	carriage->program_counter = MEM_SIZE / get_number_of_players() * (id - 1);
	ft_memset(carriage->regs, 0, REG_NUMBER);
	carriage->cycle_to_die = 0;
	carriage->last_live = 0;
	carriage->regs[0] = -id;
	carriage->live = 0;
	carriage->carry = 0;
	carriage->player_id = -id;
	carriage->prev = NULL;
	carriage->next = NULL;
}

t_carriage	*create_carriage(void)
{
	t_carriage	*carriage;

	if (!(carriage = (t_carriage*)ft_memalloc(sizeof(t_carriage))))
		exit_error(E_MALLOC);
	if (!(carriage->args = (t_arg*)ft_memalloc(sizeof(t_arg) * MAX_ARGS)))
		exit_error(E_MALLOC);
	return (carriage);
}

void		set_starter_kit_carriage(t_carriage **carriage, uint8_t *arena)
{
	uint8_t	count_champ;

	count_champ = get_number_of_players();
	while (count_champ > 0)
	{
		add_carriage(carriage, arena, count_champ);
		count_champ--;
	}
}

t_carriage	*copy_carriage(t_carriage *car)
{
	t_carriage	*copy;

	copy = create_carriage();
	ft_memcpy(copy->regs, car->regs, sizeof(int32_t) * REG_NUMBER);
	copy->live = car->live;
	copy->carry = car->carry;
	return (copy);
}

void		add_carriage(t_carriage **car, uint8_t *arena, uint8_t id)
{
	t_carriage	*new_car;

	new_car = create_carriage();
	init_carriage(new_car, arena, id);
	if (*car)
	{
		(*car)->prev = new_car;
		new_car->next = *car;
	}
	*car = new_car;
}
