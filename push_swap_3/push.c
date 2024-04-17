/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:45:30 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/17 14:50:15 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_link *dst, t_link *src)
{
	if (!src || src->count < 1)
		return ;
	dst->arr[dst->count] = src->arr[0];
	dst->count++;
	src->count--;
}

void	pa(t_link *a, t_link *b)
{
	push(a, b);
	ft_write(1, "pa\n", 3);
}

void	pb(t_link *a, t_link *b)
{
	push(b, a);
	ft_write(1, "pb\n", 3);
}
