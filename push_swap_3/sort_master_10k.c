/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_master_10k.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:11:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/25 20:57:30 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_nearest(t_link *stack)
{
	int i;

	i = 0;
	while (i < stack->count)
	{
		if (stack->nearest[i])
			return (i);
		i++;
	}
	return (0);
}



void	push_sort(t_stack *stack)
{
	stack->b->min = get_nearest(stack->b);
	if (stack->b->midle[stack->b->min]
		&& stack->a->midle[stack->b->goal[stack->b->min]])
	{
		while (stack->a->arr[0] != stack->b->goal[stack->b->min]
			&& stack->b->arr[0] != stack->b->nearest[stack->b->min])
		{
			rr(stack->a, stack->b);
			init(stack);
		}
	}
	else if (!stack->b->midle[stack->b->min]
		&& !stack->a->midle[stack->b->goal[stack->b->min]])
	{
		while (stack->a->arr[0] != stack->b->goal[stack->b->min]
			&& stack->b->arr[0] != stack->b->nearest[stack->b->min])
		{
			rrr(stack->a, stack->b);
			init(stack);
		}
	}
	rotations_b(stack);
	rotations_a(stack);
	pa(stack->a, stack->b);
}

void	big_push_swap(t_stack *stack)
{
	insertion_sort1(stack);
	if (stack->a->count <= 6 && !sorted(stack->a))
	{
		while (stack->a->count >= 4)
		{
			init(stack);
			rotations_a(stack);
			pb(stack->a, stack->b);
		}
	}
	else
	{
		while (stack->a->count >= 4)
			pb(stack->a, stack->b);
	}
	sort_3(stack);
	while (stack->b->count > 0)
	{
		init(stack);
		push_sort(stack);	
	}
	printf("a min: %d\n", stack->a->min);
}
