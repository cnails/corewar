/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_st_sti_sub_xor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/12/05 19:44:34 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			op_or(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, THIRD);
	regs[args[THIRD].value - 1] = args[FIRST].value | args[SECOND].value;
	carriage->carry = regs[args[THIRD].value - 1] == 0 ? 1 : 0;
}

void			op_st(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	int32_t		i;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	if (args[SECOND].type == IND_CODE)
	{
		address = carriage->program_counter + args[SECOND].value % IDX_MOD;
		i = 0;
		while (i < 4)
		{
			*(vm->arena + address + i) = (regs[args[FIRST].value - 1] >> \
												((3 - i) * CHAR_BIT)) & 0xFF;
			i++;
		}
	}
	else if (args[SECOND].type == REG_CODE)
		regs[args[SECOND].value - 1] = regs[args[FIRST].value - 1];
}

void			op_sti(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	int			i;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, FIRST);
	address = carriage->program_counter + (args[SECOND].value + \
												args[THIRD].value) % MEM_SIZE;
	address = address < 0 ? MEM_SIZE + address : address;
	i = 0;
	while (i < 4)
	{
		*(vm->arena + (address + i) % MEM_SIZE) = (regs[args[FIRST].value - 1] \
												>> ((3 - i) * CHAR_BIT)) & 0xFF;
		i++;
	}
}

void			op_sub(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	(void)vm->arena;
	regs[args[THIRD].value - 1] = regs[args[FIRST].value - 1] - \
												regs[args[SECOND].value - 1];
	if (regs[args[THIRD].value - 1] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

void			op_xor(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, THIRD);
	regs[args[THIRD].value - 1] = args[FIRST].value ^ args[SECOND].value;
	carriage->carry = regs[args[THIRD].value - 1] == 0 ? 1 : 0;
}
