/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:45:30 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/10 16:03:14 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief pushes the first element of stack src to stack dst
/// @param dst destination stack
/// @param src source stack
static	void	push(t_link *dst, t_link *src)
{
	int	i;

	if (!src || src->count < 1)
		return ;
	i = dst->count;
	while (i > 0)
	{
		dst->arr[i] = dst->arr[i - 1];
		i--;
	}
	dst->arr[0] = src->arr[0];
	dst->count++;
	i = 0;
	while (i < src->count - 1)
	{
		src->arr[i] = src->arr[i + 1];
		i++;
	}
	src->count--;
}

/// @brief pushes the first element of stack b to stack a
/// @param a the stack a
/// @param b the stack b
void	pa(t_link *a, t_link *b)
{
	push(a, b);
	ft_write(1, "pa\n", 3);
}

/// @brief pushes the first element of stack a to stack b
/// @param a the stack a
/// @param b the stack b
void	pb(t_link *a, t_link *b)
{
	push(b, a);
	ft_write(1, "pb\n", 3);
}

void	error0(int err_num)
{
	if (err_num == -1)
		ft_write(2, "Error\n Use ./push_swap \"1 2 3 .. \" OR 1 2 3..\n", 47);
	if (err_num == 0)
		ft_write(1, "Error\n first Malloc NULL\n", 26);
	exit(EXIT_FAILURE);
}
