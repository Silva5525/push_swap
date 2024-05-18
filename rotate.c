/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:51:38 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 23:28:19 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief rotate first and last element of the list
/// @param link The list to rotate.
static void	rotate(t_link *link)
{
	ssize_t	tmp;
	int		i;

	i = 0;
	if (!link || link->count < 2)
		return ;
	tmp = link->arr[0];
	while (i < link->count - 1)
	{
		link->arr[i] = link->arr[i + 1];
		i++;
	}
	link->arr[i] = tmp;
}

void	ra(t_link *a)
{
	rotate(a);
	ft_write(1, "ra\n", 3);
}

void	rb(t_link *b)
{
	rotate(b);
	ft_write(1, "rb\n", 3);
}

void	rr(t_link *a, t_link *b)
{
	rotate(a);
	rotate(b);
	ft_write(1, "rr\n", 3);
}
