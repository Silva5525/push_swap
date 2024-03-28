/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:20:20 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 12:20:30 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotation(t_link **a)
{
	t_link	*tmp;
	int		len;

	len = stack_len(*a);
	if (len < 2 || !a)
		return ;
	tmp = *a;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp->prev->next = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	*a = tmp;
	tmp->next->prev = tmp;
}

void	rra(t_link **a)
{
	reverse_rotation(a);
	ft_write(1, "rra\n", 5);
}

void	rrb(t_link **b)
{
	reverse_rotation(b);
	ft_write(1, "rrb\n", 5);
}

void	rrr(t_link **a, t_link **b)
{
	reverse_rotation(a);
	reverse_rotation(b);
	ft_write(1, "rrr\n", 5);
}
