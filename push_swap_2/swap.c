/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:23:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/10 11:50:15 by wdegraf          ###   ########.fr       */
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

void	sa(t_link *a)
{
	swap(&a);
	ft_write(1, "sa\n", 3);
}

void	sb(t_link *b)
{
	swap(&b);
	ft_write(1, "sb\n", 3);
}

void	ss(t_link *a, t_link *b)
{
	swap(&a);
	swap(&b);
	ft_write(1, "ss\n", 3);
}
