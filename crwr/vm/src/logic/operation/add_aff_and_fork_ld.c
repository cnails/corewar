/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_aff_and_fork_ld.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/12/05 19:44:10 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_add(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	regs[args[THIRD].value - 1] = regs[args[FIRST].value - 1] + \
												regs[args[SECOND].value - 1];
	if (regs[args[THIRD].value - 1] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	(void)vm;
}

void		op_aff(t_vm *vm, t_carriage *carriage)
{
	(void)vm;
	(void)carriage;
}

void		op_and(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, THIRD);
	regs[args[THIRD].value - 1] = args[FIRST].value & args[SECOND].value;
	carriage->carry = regs[args[THIRD].value - 1] == 0 ? 1 : 0;
	(void)vm;
}

void		op_fork(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	t_carriage	*copy;
	extern t_op	g_optab[17];

	args = carriage->args;
	copy = carriage;
	(void)vm->arena;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = copy_carriage(carriage);
	copy->next->prev = copy;
	copy = copy->next;
	copy->program_counter = args[FIRST].value % IDX_MOD;
}

void		op_ld(t_vm *vm, t_carriage *carriage)
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
			address = (carriage->program_counter + args[i].value % IDX_MOD) % \
																	MEM_SIZE;
			args[i].value = *(vm->arena + address + (address > 0 ? 0 \
																: MEM_SIZE));
		}
		i++;
	}
	carriage->regs[args[SECOND].value - 1] = args[FIRST].value;
	carriage->carry = carriage->regs[args[SECOND].value - 1] == 0 ? 1 : 0;
}
