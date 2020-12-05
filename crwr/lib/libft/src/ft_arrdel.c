/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 22:18:00 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void			ft_arrdel(void ***arr)
{
	void		**first;

	if (!arr || !(*arr))
		return ;
	first = *arr;
	while (**arr)
	{
		free(**arr);
		(*arr)++;
	}
	free(first);
	first = NULL;
	*arr = first;
}
