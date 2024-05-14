/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:31:57 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 13:11:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotation(t_link **a)
{
	t_link *tmp;
	int i;
	
	i = stack_len(*a);
	if (i > 2 )
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
}

void	ra(t_link **a)
{
	rotation(a);
	write(1, "ra\n", 3);
}

void	rb(t_link **b)
{
	rotation(b);
	write(1, "rb\n", 3);
}

void	rr(t_link **a, t_link **b)
{
	rotation(a);
	rotation(b);
	write(1, "rr\n", 3);
}
