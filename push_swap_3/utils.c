/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:10:58 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/03 16:32:45 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief finds the position of the smallest element in the stack and saves it in stack->min
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

/// @brief it finds the smallest element in a that is still larger than 
/// the given element in b  
/// @param a stack a /// not used
/// @param b->goal[i] is the smallest element in a that is still 
/// larger than the given element in b
/// the finish position of the element in stack a
/// if not foundsets the goal to the position of the smallest element in a
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
			b->goal[i] = min_i(a);
		i++;
	}
}

/// @brief checks the position of the elements in the stack and sets under
/// the midle of the stack to true and the above to false
/// @param stack->pos[i] the position of the elements in the stack
/// @param stack->midle[i] true or false if the element is under or above the midle
void	check_position(t_link *stack)
{
	int	i;
	int midle;
	
	midle = stack->count / 2;
	i = 0;
	while (i < stack->count)
	{
		stack->pos[i] = i;
		stack->midle[i] = (i < midle);
		// printf("stack->midle[i] = %d\n", stack->midle[i]);
		i++;
	}
}

/// @brief sets the distance of the elements in the stack between the goal
/// and the element which will be pushed
/// @param a stack a /// not used
/// @param b->distance the distance of the element to the goal
void	count_distance(t_link *a, t_link *b)
{
	int	i;
	// printf("count distance\n");
	i = 0;
	while (i < b->count)
	{
		b->distance[i] = b->pos[i];
		if (!b->midle[i])
			b->distance[i] = b->count - b->pos[i];
		// printf("b->distance[i] = %d\n", b->distance[i]);
		if (b->goal[i] <= a->count / 2)
		{
			b->distance[i] += b->goal[i];
		// printf("b->goal[i] = %d\n", b->goal[i]);
		// printf("b->distance[i] = %d\n", b->distance[i]);
		}
		else
			b->distance[i] += a->count - b->goal[i]; /// check if goal b and a are correct in if else
		// printf("b->goal[i] = %d\n", b->goal[i]);
		// printf("b->distance[i] = %d\n", b->distance[i]);
		i++;
	}
	// printf("count distance end\n");
}

/// @brief gives the nearest element for the b stack to push it checks the lowest b->distance
/// @param b->nearest[i] is true if the element is the nearest all other are false
/// @param a stack a /// not used
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
		// printf("b->distance[i] = %d\n", b->distance[i]);
		if (b->distance[i] == best)
			b->nearest[i] = true;
		else
			b->nearest[i] = false;
		// printf("b->nearest[i] = %d\n", b->nearest[i]);
		i++;
	}
}

/// @brief mallocs the needed memory for the sorting values
/// @param stack holds the stacks a and b
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

/// @brief initializes the values needet for sorting
/// @param stack holder of the stack
void	init(t_stack *stack)
{
	// printf("a\n");
	check_position(stack->a);
	// printf("b\n");
	check_position(stack->b);
	give_position(stack->a, stack->b);
	count_distance(stack->a, stack->b);
	give_nearest(stack->b);
}
