/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *buff;

	buff = *begin_list1;
	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (buff->next)
		buff = buff->next;
	buff->next = begin_list2;
}
