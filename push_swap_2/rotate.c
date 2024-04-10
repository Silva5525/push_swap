/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:51:38 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/10 12:50:51 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief rotate the list link by using a *tmp holder to store the first
/// element, move *link to the last element and connect the last element to
/// the first element.
/// @param link The list to rotate.
static void	rotate(t_link **link)
{
	t_link	*tmp;

	if (!*link || !(*link)->next)
		return ;
	tmp = *link;
	*link = (*link)->next;
	(*link)->prev = NULL;
	while ((*link)->next)
		*link = (*link)->next;
/// The while could be more efficient with a tracked end of list..
	(*link)->next = tmp;
	tmp->prev = *link;
}

void	ra(t_link *a)
{
	rotate(&a);
	ft_write(1, "ra\n", 3);
}

void	rb(t_link *b)
{
	rotate(&b);
	ft_write(1, "rb\n", 3);
}

void	rr(t_link *a, t_link *b)
{
	rotate(&a);
	rotate(&b);
	ft_write(1, "rr\n", 3);
}
