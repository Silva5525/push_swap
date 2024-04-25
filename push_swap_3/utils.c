/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:10:58 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/25 19:14:29 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief finds the position of the smallest element in the stack
/// @param stack holder of the stack
/// @return the position of the smallest element
int	find_min(t_link *stack)
{
	int	i;
	int	min;
	int	position;

	i = 0;
	min = INT_MAX;
	position = 0;
	while (i < stack->count)
	{
		if (stack->arr[i] < min)
		{
			stack->min = stack->arr[i];
			position = i;
		}
		i++;
	}
	return (position);
}

/// @brief gives evry b element a position in the a stack 
/// @param a stack a
/// @param b stack b
static void give_position(t_link *a, t_link *b)
{
	int		position;
	int		i;
	int		j;
	int		big;
	
	i = 0;
	while (i < b->count)
	{
		big = INT_MAX;
		j = 0;
		while (j < a->count)
		{
			if (a->arr[j] < big && a->arr[j] > b->arr[i])
			{
				big = a->arr[j];
				position = j;
			}
			j++;
		}
		if (INT_MAX != big)
			b->goal[i] = position;
		else
			b->goal[i] = find_min(a);
		i++;
	}
}

/// @brief checks the position of the elements in the stack and sets under
/// the midle of the stack to true and the above to false
/// @param stack holder of the stack
void	check_position(t_link *stack)
{
	int	i;

	i = 0;
	while (i < stack->count)
	{
		stack->pos[i] = i;
		if (i <= stack->count / 2)
			stack->midle[i] = true;
		else
			stack->midle[i] = false;
		i++;
	}
}

/// @brief sets the distance of the elements in the stack between the goal
/// and the element which will be pushed
/// @param a stack a
/// @param b stack b
void	count_distance(t_link *a, t_link *b)
{
	int	i;

	i = 0;
	while (i < b->count)
	{
		b->distance[i] = b->pos[i];
		if (!b->midle[i])
			b->distance[i] = b->count - b->pos[i];
		if (b->goal[i] <= a->count / 2)
			b->distance[i] += b->goal[i];
		else
			b->distance[i] += a->count - b->goal[i]; /// check if goal b and a are correct in if else
		i++;
	}
}

/// @brief gives the nearest element for the b stack to push
/// @param b the b stack
void	give_nearest(t_link *b)
{
	int best;
	int i;
	
	i = 0;
	if (b->count <= 1)
	{
		b->nearest[i] = true;
		return ;
	}
	best = INT_MAX;
	while (i < b->count)
	{
		if (b->distance[i] < best)
			best = b->distance[i];
		i++;
	}
	i = 0;
	while (i < b->count)
	{
		if (b->distance[i] == best)
			b->nearest[i] = true;
		else
			b->nearest[i] = false;
		i++;
	}
}

void	init_int(t_stack *stack)
{
	int count;

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

void	init(t_stack *stack)
{
	check_position(stack->a);
	check_position(stack->b);
	give_position(stack->a, stack->b);
	count_distance(stack->a, stack->b);
	give_nearest(stack->b);
}
