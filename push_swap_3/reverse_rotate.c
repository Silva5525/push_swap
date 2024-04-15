/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:20:10 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/10 12:47:37 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/// @brief reverse_rotate the list link by using a *tmp holder
/// the if checks for the case of an empty list or a list with only one element
/// tmp takes the *link pointer and takes it in the while loop to the list-end
/// then the end of list is connected to the beginning of the list
/// @param link the list to reverse_rotate
static void	reverse_rotate(t_link **link)
{
	t_link	*tmp;

	if (!*link || !(*link)->next)
		return ;
	tmp = *link;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *link;
	(*link)->prev = tmp;
	*link = tmp;
	tmp->prev = NULL;
}

void	rra(t_link *a)
{
	reverse_rotate(&a);
	ft_write(1, "rra\n", 4);
}

void	rrb(t_link *b)
{
	reverse_rotate(&b);
	ft_write(1, "rrb\n", 4);
}

void	rrr(t_link *a, t_link *b)
{
	reverse_rotate(&a);
	reverse_rotate(&b);
	ft_write(1, "rrr\n", 4);
}
