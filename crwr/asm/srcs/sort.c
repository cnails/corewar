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

void		push_back(char *label, t_sort **sort)
{
	t_sort	*last;
	t_sort	*tmp;

	last = get_next(*sort);
	tmp = add_sorted(label);
	if (last == NULL)
	{
		(*sort) = tmp;
	}
	else
	{
		last->next = tmp;
	}
}

void		del_sorted(t_sort **sort)
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

t_sort		*get_next(t_sort *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

t_sort		*add_sorted(char *label)
{
	t_sort	*sort;

	sort = (t_sort*)malloc(sizeof(t_sort));
	if (!sort)
		return (NULL);
	sort->label = label;
	sort->next = NULL;
	return (sort);
}
