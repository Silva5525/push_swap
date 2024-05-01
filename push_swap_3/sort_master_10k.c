/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_master_10k.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:11:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/27 19:26:15 by wdegraf          ###   ########.fr       */
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

// / is not correct
void	push_sort(t_stack *stack)
{
	// int near;
	// int	midle_a;

	// midle_a = stack->a->count / 2;
	// /// is not correct
	// near = get_nearest(stack->b);
	// if (stack->b->midle[near]
	// 	&& stack->a->pos[midle_a] < stack->a->pos[stack->b->goal[near]])
	// {
	// 	printf("1\n");
	// 	while (stack->a->arr[0] != stack->a->pos[stack->b->goal[near]]
	// 		&& stack->b->arr[0] != stack->b->arr[near])
	// 	{
	// 		rr(stack->a, stack->b);
	// 		init(stack);
	// 	}
	// }
	// else if (!stack->b->midle[near]
	// 	&& stack->a->pos[midle_a] > stack->a->pos[stack->b->goal[near]])
	// {
	// 	printf("2\n");
	// 	while (stack->a->arr[0] != stack->a->pos[stack->b->goal[near]]
	// 		&& stack->b->arr[0] != stack->b->arr[near])
	// 	{
	// 		rrr(stack->a, stack->b);
	// 		init(stack);
	// 	}
	// }
	// rotations_b(stack);
	// rotations_a(stack);
	pa(stack->a, stack->b);
}

/// is not done jet
void	big_push_swap(t_stack *stack)
{
	insertion_sort1(stack);
	if (stack->a->count <= 6 && !sorted(stack->a))
	{
		while (stack->a->count > 3)
		{
			init(stack);
			rotations_a6(stack);
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
	// check_position(stack->a);
	// stack->a->min = find_min(stack->a);
	// if (stack->a->min )
		// rotations_a(stack);
	// printf("a min: %d\n", stack->a->min);
}
