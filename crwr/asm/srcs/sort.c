/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_sort		*go_to_next(t_sort *sort)
{
	if (sort == NULL)
		return (NULL);
	while (sort->next)
		sort = sort->next;
	return (sort);
}

t_sort		*push_block(char *label)
{
	t_sort	*sort;

	sort = (t_sort*)malloc(sizeof(t_sort));
	if (!sort)
		return (NULL);
	sort->label = label;
	sort->next = NULL;
	return (sort);
}

void		push_to_the_end(char *label, t_sort **sort)
{
	t_sort	*last;
	t_sort	*tmp;

	last = go_to_next(*sort);
	tmp = push_block(label);
	if (last == NULL)
	{
		(*sort) = tmp;
	}
	else
	{
		last->next = tmp;
	}
}

void		deleting_of_sort(t_sort **sort)
{
	t_sort *next;

	if (!sort || !(*sort))
		return ;
	while (*sort)
	{
		next = (*sort)->next;
		if ((*sort)->label)
			ft_strdel(&(*sort)->label);
		free((*sort));
		(*sort) = NULL;
		(*sort) = next;
	}
	if (sort && (*sort))
	{
		free((*sort));
		*sort = NULL;
	}
	sort = NULL;
}
