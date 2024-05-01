/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_master_10k.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:11:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/01 18:51:57 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief returns the position of the nearest element in the stack given
/// @param stack the t_link element which is a or b
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

/// @brief sorts stack if it has between 3 and 7 elements
/// @param stack holds the stacks a and b
void	push_swap_7(t_stack *stack)
{
	insertion_sort1(stack);
	if (stack->a->count <= 7 && !sorted(stack->a))
	{
		while (stack->a->count > 3)
			rotations_7(stack);
	}
	sort_3(stack);
	while (stack->b->count > 0)
		pa(stack->a, stack->b);	
}

/// @brief sorts the stack if it has more than 7 elements
/// @param stack holds the stacks a and b 
void 	push_swap(t_stack *stack)
{
	int half;
	
	insertion_sort1(stack);
	if (!sorted(stack->a))
	{
		while (stack->a->count > 3)
			pb(stack->a, stack->b);
	}
	sort_3(stack);
	while (stack->b->count > 0)
	{
		push_sort(stack);
	}
	init(stack);
	half = min_i(stack->a);
	if (half < stack->a->count / 2)
	{
		while (stack->a->arr[0] != stack->a->arr[half])
			ra(stack->a);
	}
	else
	{
		while (stack->a->arr[0] != stack->a->arr[half])
			rra(stack->a);
	}
}
