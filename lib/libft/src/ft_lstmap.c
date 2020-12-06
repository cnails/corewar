/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	buf = (t_list *)malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	buf = (*f)(lst);
	head = buf;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&buf, (*f)(lst));
		if (!buf)
			return (NULL);
		buf = buf->next;
	}
	return (head);
}
