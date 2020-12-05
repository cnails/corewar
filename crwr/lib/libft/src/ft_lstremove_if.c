/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
