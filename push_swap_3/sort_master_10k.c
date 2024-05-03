/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_master_10k.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:11:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/03 16:51:26 by wdegraf          ###   ########.fr       */
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
	int near;
	int pos_near;
	int goal_near;
	int arr_near;
	int midle_near;

	init(stack);
	near = get_nearest(stack->b);
	// printf("near: %d\n", near);
	// printf("stack->a->pos[near]: %d\n", stack->a->pos[near]);
	// printf("stack->b->goal[near]: %d\n", stack->b->goal[near]);
	// printf("stack->a->midle[near]: %d\n", stack->a->midle[near]);
	pos_near = stack->b->arr[near]; // arr and pos are the same.. fix this shit or delate one
	goal_near = stack->a->goal[near];
	arr_near = stack->b->arr[near];
	midle_near = stack->b->midle[near];
	if (midle_near
		&& pos_near < goal_near)
	{
		printf("1\n");
		while (stack->a->arr[0] != goal_near
			&& stack->b->arr[0] != arr_near)
		{
			printf("1\n");
			rr(stack->a, stack->b);
		}
	}
	else if (!midle_near
		&& pos_near > goal_near)
	{
		printf("2\n");
		while (stack->a->arr[0] != goal_near
			&& stack->b->arr[0] != arr_near)
		{
			rrr(stack->a, stack->b);
		}
	}
	rotations_b(stack);
	rotations_a(stack);
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
	int min;
	int pos_min;
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
		{
			rra(stack->a);
			printf("stack->a->arr[half]: %d\n", pos_min);
			printf("stack->a->arr[0]: %d\n", stack->a->arr[0]);
			printf("stack->a->count: %d\n", stack->a->count);
		}
			
	}
}
