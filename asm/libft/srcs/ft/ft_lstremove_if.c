/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*previous;
	t_list	*next;

	previous = *begin_list;
	next = *begin_list;
	while (next && (*cmp)(next->content, data_ref) == 0)
	{
		*begin_list = next->next;
		free(next);
		next = *begin_list;
	}
	while (next)
	{
		previous = *begin_list;
		while (next && (*cmp)(next->content, data_ref) != 0)
			next = next->next;
		while (next && previous->next != next)
			previous = previous->next;
		if (next)
		{
			previous->next = next->next;
			free(next);
			next = previous->next;
		}
	}
}
