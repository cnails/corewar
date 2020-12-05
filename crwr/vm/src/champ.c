/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:30:26 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 19:40:03 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champion		*create_champ(int id)
{
	t_champion	*champ;

	champ = (t_champion*)ft_memalloc(sizeof(t_champion));
	if (!champ)
		exit_error(E_MALLOC);
	init_champ(champ, id);
	return (champ);
}

static void		init_champ(t_champion *champ, int id)
{
	champ->code = NULL;
	champ->id = id;
	champ->next = NULL;
	champ->last_live = 0;
	champ->curr_lives_num = 0;
	champ->prev_lives_num = 0;
}
