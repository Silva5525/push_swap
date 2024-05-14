/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:11:05 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 12:20:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_link **link)
{
	if (!*link ||!(*link)->next)
		return ;
	*link = (*link)->next;
	(*link)->prev->prev = *link;
	(*link)->prev->next = (*link)->next;
	if((*link)->next)
	{
		(*link)->next->prev = (*link)->prev;
	}
	(*link)->next = (*link)->prev;
	(*link)->prev = NULL;
}

// for testing purposes
// static void swap(t_link **link) {
//     // Check if the list is empty or has only one node (no next node).
//     if (!*link || !(*link)->next) {
//         return;
//     }
    
//     // Assuming this is meant for a doubly linked list based on your usage of 'prev' pointers.
//     t_link *second = (*link)->next; // Save second node.
    
//     // If there's a node after the second node, update its prev pointer.
//     if (second->next) {
//         second->next->prev = *link;
//     }
    
//     // Swap the first and second nodes.
//     (*link)->next = second->next;
//     second->prev = (*link)->prev; // This should usually be NULL if *link was the first node.
//     (*link)->prev = second;
//     second->next = *link;
//     *link = second; // Update the head of the list to the second node, now the first.
// }

void	sa(t_link **a)
{
	swap(a);
	ft_write(1, "sa\n", 3);
}

void	sb(t_link **b)
{
	swap(b);
	ft_write(1, "sb\n", 3);
}

void	ss(t_link **a, t_link **b)
{
	swap(a);
	swap(b);
	ft_write(1, "ss\n", 3);
}