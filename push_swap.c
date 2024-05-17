/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:16:59 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/17 20:33:38 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief part 2 of init_ssize_t mallocs the needed memory for the sorting values
/// @param stack hold the stacks a and b
/// @param count has the count of all elements in the stack
static void	init_ssize_t2(t_stack *stack, ssize_t count)
{
	if (!stack->a->distance)
		error3(stack, 0);
	stack->a->goal = malloc(sizeof(ssize_t) * count);
	if (!stack->a->goal)
		error3(stack, 0);
	stack->b->distance = malloc(sizeof(ssize_t) * count);
	if (!stack->b->distance)
		error3(stack, 0);
	stack->b->goal = malloc(sizeof(ssize_t) * count);
	if (!stack->b->goal)
		error3(stack, 0);
	stack->b->nearest = malloc(sizeof(bool) * count);
	if (!stack->b->nearest)
		error3(stack, 0);
	stack->a->nearest = malloc(sizeof(bool) * count);
	if (!stack->a->nearest)
		error3(stack, 0);
}

/// @brief mallocs the needed memory for the sorting values
/// @param stack holds the stacks a and b
void	init_int(t_stack *stack)
{
	ssize_t	count;

	count = stack->a->count + stack->b->count;
	stack->a->pos = malloc(sizeof(ssize_t) * count);
	if (!stack->a->pos)
		error3(stack, 0);
	stack->a->midle = malloc(sizeof(ssize_t) * count);
	if (!stack->a->midle)
		error3(stack, 0);
	stack->b->pos = malloc(sizeof(ssize_t) * count);
	if (!stack->b->pos)
		error3(stack, 0);
	stack->b->midle = malloc(sizeof(ssize_t) * count);
	if (!stack->b->midle)
		error3(stack, 0);
	stack->a->distance = malloc(sizeof(ssize_t) * count);
	init_ssize_t2(stack, count);
}

/// @brief finds the position of the smallest element
/// in the stack and saves it in stack->min
/// @param stack->min the smallest ssize_t in the stack
/// @return @param position of the smallest element
ssize_t	min_i(t_link *stack)
{
	ssize_t	i;
	ssize_t	position;

	i = 0;
	stack->min = INT_MAX;
	position = 0;
	while (i < stack->count)
	{
		if (stack->arr[i] < stack->min)
		{
			stack->min = stack->arr[i];
			position = i;
		}
		i++;
	}
	return (position);
}

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		error3(*stack, 0);
	(*stack)->a = malloc(sizeof(t_link));
	if (!(*stack)->a)
		error3(*stack, 0);
	(*stack)->b = malloc(sizeof(t_link));
	if (!(*stack)->b)
		error3(*stack, 0);
}

// void big_push_swap(t_stack stack)
// {

// 	ft_sort(stack);
// }

// ssize_t	ft_place(t_stack *stack)
// {
// 	ssize_t	i;
// 	i = 1;
// 	if (stack->a->arr[0] > stack->b->arr[0]
// 	&& stack->a->arr[0] < stack->b->arr[stack->b->count - 1])
// 		i = 0;
// 	else if (stack->a->arr[0] > stack->b->max
//	|| stack->a->arr[0] < stack->b->min)
// 	{
// 		// while (stack->a->arr[0] < stack->b->max)
// 		// 	i++;
// 		//here somehow it should be checked for 
// 	}
// 	else
// 	{
// 		tmp = stack->b->[]
// 	}
// }