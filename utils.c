/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:10:58 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 23:11:55 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief it finds the smallest element in a that is still larger than 
/// the given element in b  
/// @param a stack a /// not used
/// @param b->goal[i] is the smallest element in a that is still 
/// larger than the given element in b
/// the finish position of the element in stack a
/// if not foundsets the goal to the position of the smallest element in a
static void	give_position(t_link *a, t_link *b)
{
	ssize_t		position;
	ssize_t		i;
	ssize_t		j;
	ssize_t		big;

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
/// @param stack->midle[i] true or false if the element is under or above
/// the midle
void	check_position(t_link *stack)
{
	ssize_t	i;
	ssize_t	midle;

	midle = stack->count / 2;
	i = 0;
	while (i < stack->count)
	{
		stack->pos[i] = i;
		stack->midle[i] = (i < midle);
		i++;
	}
}

/// @brief sets the distance of the elements in the stack between the goal
/// and the element which will be pushed
/// @param a stack a /// not used
/// @param b->distance the distance of the element to the goal
void	count_distance(t_link *a, t_link *b)
{
	ssize_t	i;

	i = 0;
	while (i < b->count)
	{
		b->distance[i] = b->pos[i];
		if (!b->midle[i])
			b->distance[i] = b->count - b->pos[i];
		if (b->goal[i] <= a->count / 2)
			b->distance[i] += b->goal[i];
		else
			b->distance[i] += a->count - b->goal[i];
		i++;
	}
}

/// @brief gives the nearest element for the b stack to push it checks
/// the lowest b->distance
/// @param b->nearest[i] is true if the element is the nearest all
/// other are false
/// @param a stack a /// not used
void	give_nearest(t_link *b)
{
	ssize_t	best;
	ssize_t	i;

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

/// @brief initializes the values needet for sorting
/// @param stack holder of the stack
void	init(t_stack *stack)
{
	check_position(stack->a);
	check_position(stack->b);
	give_position(stack->a, stack->b);
	count_distance(stack->a, stack->b);
	give_nearest(stack->b);
}
