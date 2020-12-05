/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:17:21 by cnails            #+#    #+#             */
/*   Updated: 2020/12/05 20:19:31 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_arrptr(void *arr[])
{
	uint32_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}

void		free_carriage_list(t_carriage **head)
{
	t_carriage *current;

	if (!head)
		return ;
	while (*head)
	{
		current = (*head);
		*head = (*head)->next;
		free_carriage(current);
	}
}

void		init_arrptr(void **array, uint32_t size)
{
	uint32_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
}

void		free_champ(t_champion *champ[])
{
	uint8_t	i;

	i = 0;
	if (!champ)
		return ;
	while (champ[i])
	{
		free(champ[i]->code);
		free(champ[i]);
		champ[i] = NULL;
		i++;
	}
}

void		free_carriage(t_carriage *car)
{
	if (!car)
		return ;
	free(car->args);
	free(car);
}
