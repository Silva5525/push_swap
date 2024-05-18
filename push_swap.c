/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_master_10k.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:11:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 12:43:24 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief returns the position of the nearest element in the stack given
/// @param stack the t_link element which is a or b
ssize_t	get_nearest(t_link *stack)
{
	ssize_t	i;

	i = 0;
	while (i < stack->count)
	{
		if (stack->nearest[i])
			return (i);
		i++;
	}
	return (0);
}

static void	double_rotatations(t_stack *stack, ssize_t near)
{
	ssize_t	arr0;
	ssize_t	goal_near;
	ssize_t	arr_near;
	ssize_t	midle_near;

	arr0 = stack->b->arr[0];
	goal_near = stack->b->goal[near];
	arr_near = stack->b->arr[near];
	midle_near = stack->b->midle[near];
	if (midle_near && (arr0 > goal_near))
	{
		while (stack->a->arr[0] != goal_near
			&& stack->b->arr[0] != arr_near)
			rr(stack->a, stack->b);
		init(stack);
	}
	else if (!midle_near && (arr0 > goal_near))
	{
		while (stack->a->arr[0] != goal_near
			&& stack->b->arr[0] != arr_near)
			rrr(stack->a, stack->b);
		init(stack);
	}
}

/// @brief sorts the stack a and b depending on the nearest element in b
/// @param stack 
void	push_sort(t_stack *stack)
{
	ssize_t	near;

	init(stack);
	near = get_nearest(stack->b);
	double_rotatations(stack, near);
	rotations_b(stack);
	rotations_a(stack);
	pa(stack->a, stack->b);
}

/// @brief sorts stack if it has between 3 and 7 elements
/// @param stack holds the stacks a and b
void	push_swap_7(t_stack *stack)
{
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
void	push_swap(t_stack *stack)
{
	ssize_t	min;
	ssize_t	pos_min;

	if (!sorted(stack->a))
	{
		while (stack->a->count > 3)
			pb(stack->a, stack->b);
	}
	sort_3(stack);
	while (stack->b->count > 0)
		push_sort(stack);
	min = min_i(stack->a);
	pos_min = stack->a->arr[min];
	if (min < (stack->a->count / 2))
	{
		while (stack->a->arr[0] != pos_min)
			ra(stack->a);
	}
	else
	{
		while (stack->a->arr[0] != pos_min)
			rra(stack->a);
	}
}
