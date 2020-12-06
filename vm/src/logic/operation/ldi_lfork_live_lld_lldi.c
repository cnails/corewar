/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_lfork_live_lld_lldi.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/12/05 19:39:54 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

void		op_ldi(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	args = take_args(vm->arena, carriage, THIRD);
	address = carriage->program_counter + (args[FIRST].value \
												+ args[SECOND].value) % IDX_MOD;
	address = address < 0 ? MEM_SIZE + address : address;
	regs[args[THIRD].value - 1] = get_arg(vm->arena, address, REG_CODE, \
												g_optab[carriage->opcode - 1]);
}

void		op_lfork(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	t_carriage	*copy;
	extern t_op	g_optab[17];

	args = carriage->args;
	copy = carriage;
	while (copy->next != NULL)
		copy = copy->next;
	(void)vm->arena;
	copy->next = copy_carriage(carriage);
	copy->next->prev = copy;
	copy = copy->next;
	copy->program_counter = args[FIRST].value % MEM_SIZE;
}

void		op_live(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		player_id;
	t_champion	*champ;
	extern t_op	g_optab[17];

	args = carriage->args;
	vm->lives_num++;
	carriage->last_live = vm->iter_from_start;
	player_id = args[FIRST].value;
	if (player_id <= -1 && player_id >= -vm->count_champs)
	{
		champ = vm->champ[(-player_id) - 1];
		champ->last_live = vm->iter_from_start;
		champ->curr_lives_num++;
		vm->last_alive = champ;
	}
}

void		op_lld(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		i;
	int32_t		address;
	extern t_op	g_optab[17];

	i = 0;
	args = carriage->args;
	while (i < g_optab[carriage->opcode - 1].col_args)
	{
		if (args[i].type == IND_CODE)
		{
			address = carriage->program_counter + args[i].value % MEM_SIZE;
			args[i].value = *(vm->arena + address + (address > 0 ? 0 : \
																	MEM_SIZE));
		}
		i++;
	}
	carriage->regs[args[SECOND].value - 1] = args[FIRST].value;
	carriage->carry = carriage->regs[args[SECOND].value - 1] == 0 ? 1 : 0;
}

void		op_lldi(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, THIRD);
	address = carriage->program_counter + (args[FIRST].value \
											+ args[SECOND].value) % MEM_SIZE;
	address = address < 0 ? MEM_SIZE + address : address;
	regs[args[THIRD].value - 1] = get_arg(vm->arena, address, REG_CODE, \
												g_optab[carriage->opcode - 1]);
	carriage->carry = regs[args[THIRD].value - 1] == 0 ? 1 : 0;
}
