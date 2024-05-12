/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:16:59 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/12 17:33:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief part 2 of init_int mallocs the needed memory for the sorting values
/// @param stack hold the stacks a and b
/// @param count has the count of all elements in the stack
static void	init_int2(t_stack *stack, int count)
{
	if (!stack->a->distance)
		error3(stack, 0);
	stack->a->goal = malloc(sizeof(int) * count);
	if (!stack->a->goal)
		error3(stack, 0);
	stack->b->distance = malloc(sizeof(int) * count);
	if (!stack->b->distance)
		error3(stack, 0);
	stack->b->goal = malloc(sizeof(int) * count);
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
	int	count;

	count = stack->a->count + stack->b->count;
	stack->a->pos = malloc(sizeof(int) * count);
	if (!stack->a->pos)
		error3(stack, 0);
	stack->a->midle = malloc(sizeof(int) * count);
	if (!stack->a->midle)
		error3(stack, 0);
	stack->b->pos = malloc(sizeof(int) * count);
	if (!stack->b->pos)
		error3(stack, 0);
	stack->b->midle = malloc(sizeof(int) * count);
	if (!stack->b->midle)
		error3(stack, 0);
	stack->a->distance = malloc(sizeof(int) * count);
	init_int2(stack, count);
}

/// @brief finds the position of the smallest element
/// in the stack and saves it in stack->min
/// @param stack->min the smallest int in the stack
/// @return @param position of the smallest element
int	min_i(t_link *stack)
{
	int	i;
	int	position;

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

void	check_stack(t_stack *stack)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	printf("stack->a->count: %d\n", stack->a->count);
	while (i < stack->a->count)
	{
		printf("stack->a->arr[%d]: %d\n", i, stack->a->arr[i]);
		i++;
	}
	if (sorted(stack->a))
		error3(stack, 2);
	printf("stack->a->count: %d\n", stack->a->count);
	i = 0;
	while (i < stack->a->count)
	{
		printf("stack->a->arr[%d]: %d\n", i, stack->a->arr[i]);
		i++;
	}
	while (i < stack->a->count)
	{
		j = 0;
		while (j < stack->a->count)
		{
			if (stack->a->arr[i] == stack->a->arr[j] && i != j)
				error3(stack, 10);
			j++;
		}
		i++;
	}
}

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		error0(0);
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

// int	ft_place(t_stack *stack)
// {
// 	int	i;
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