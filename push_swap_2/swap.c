/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:23:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/07 20:17:06 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_link **link)
{
	t_link	*tmp;

	if (!*link || !(*link)->next)
		return ;
	tmp = (*link)->next;
	(*link)->next = tmp->next;
	if ((tmp->next))
		(tmp->next->prev) = *link;
	tmp->prev = (*link)->prev;
	tmp->next = *link;
	(*link)->prev = tmp;
	if (tmp->prev)
		(tmp->prev->next) = tmp;
	(*link) = tmp;
}
