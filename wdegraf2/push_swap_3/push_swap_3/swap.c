/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:23:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/17 13:56:01 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief the swap function swaps the first two elements of the list
/// if the list is empty or has only one element, the function returns
/// @param link the array to swap
static void	swap(t_link *link)
{
	int	tmp;

	if (!link || link->count < 2)
		return ;
	tmp = link->arr[0];
	link->arr[0] = link->arr[1];
	link->arr[1] = tmp;
}

void	sa(t_link *a)
{
	swap(a);
	ft_write(1, "sa\n", 3);
}

void	sb(t_link *b)
{
	swap(b);
	ft_write(1, "sb\n", 3);
}

void	ss(t_link *a, t_link *b)
{
	swap(a);
	swap(b);
	ft_write(1, "ss\n", 3);
}
