/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:20:10 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/10 15:04:11 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief reverse_rotate the arrby using a tmp holder
/// the if checks for the case of an empty list or a list with only one element
/// tmp takes the link value and takes it in the while loop to the arr end
/// then end is becomming the first element
/// @param link the list to reverse_rotate
static void	reverse_rotate(t_link *link)
{
	int	tmp;
	int	i;

	if (!link || link->count < 2)
		return ;
	i = link->count - 1;
	tmp = link->arr[link->count - 1];
	while (i > 0)
	{
		link->arr[i] = link->arr[i - 1];
		i--;
	}
	link->arr[0] = tmp;
}

void	rra(t_link *a)
{
	reverse_rotate(a);
	ft_write(1, "rra\n", 4);
}

void	rrb(t_link *b)
{
	reverse_rotate(b);
	ft_write(1, "rrb\n", 4);
}

void	rrr(t_link *a, t_link *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_write(1, "rrr\n", 4);
}
