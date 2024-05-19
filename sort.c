/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:46:54 by mahakala          #+#    #+#             */
/*   Updated: 2024/05/19 13:04:34 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief rotates the stack b to the target witch is the nearest element 
/// depending if upper or lower half position. 
/// @param stack holder of the stack a and b
void	rotations_b(t_stack *stack)
{
	ssize_t	near_pos;
	ssize_t	target;
	ssize_t	midle;

	near_pos = get_nearest(stack->b);
	target = stack->b->arr[near_pos];
	midle = (stack->b->count / 2);
	while (stack->b->arr[0] != target)
	{
		if (near_pos < midle)
			rb(stack->b);
		else
			rrb(stack->b);
	}
}

/// @brief rotates the stack a to the goal target witch is the nearest element 
/// depending if upper or lower half position. 
/// @param stack holder of the stack a and b
void	rotations_a(t_stack *stack)
{
	ssize_t	near_pos;
	ssize_t	goal;
	ssize_t	target;
	ssize_t	midle;

	near_pos = get_nearest(stack->b);
	goal = stack->b->goal[near_pos];
	target = stack->a->arr[goal];
	midle = (stack->a->count / 2);
	while (stack->a->arr[0] != target)
	{
		if (goal < midle)
			ra(stack->a);
		else
			rra(stack->a);
	}
}

/// @brief rotates the stack a to the smallest element in the stack a.
/// Up if the smallest is in uper half and down if the smallest is in
/// the lower half
/// @param stack the holder of the stack a and b
void	rotations_7(t_stack *stack)
{
	ssize_t	min_pos;
	ssize_t	target;

	init(stack);
	min_pos = min_i(stack->a);
	target = stack->a->arr[min_pos];
	while (stack->a->arr[0] != target)
	{
		if (min_pos < (stack->a->count / 2))
			ra(stack->a);
		else
			rra(stack->a);
	}
	pb(stack->a, stack->b);
}

/// @brief checks if the list is sorted in ascending order
/// @param stack is the struct holder of the stack a and b but it checks only a
/// @return 1 if the list is sorted, 0 if not
ssize_t	sorted(t_link *stack)
{
	ssize_t	i;

	i = 1;
	while (i < stack->count)
	{
		if (stack->arr[i] < stack->arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

/// @brief sorts the stack a till 3 values.
/// @param stack the holder of the stack.
void	sort_3(t_stack *stack)
{
	if (stack->a->arr[1] < stack->a->arr[0]
		&& stack->a->arr[2] < stack->a->arr[0])
		ra(stack->a);
	else if (stack->a->arr[1] > stack->a->arr[0]
		&& stack->a->arr[1] > stack->a->arr[2])
		rra(stack->a);
	if (stack->a->arr[1] < stack->a->arr[0])
		sa(stack->a);
}

//// @brief insertion_sort sorts the list by taking the first element and 
//// comparing it with the next element. If the next element is smaller than
//// the first element, the next element is inserted at the right position.
//// @param stack is the struct holder of the stack a and b but it sorts only a
// void	insertion_sort1(t_stack *stack)
// {
// 	ssize_t	i;
// 	ssize_t	j;
// 	ssize_t	tmp;

// 	i = 1;
// 	while (i < stack->map->count)
// 	{
// 		tmp = stack->map->arr[i];
// 		j = i - 1;
// 		while (j >= 0 && stack->map->arr[j] > tmp)
// 		{
// 			stack->map->arr[j + 1] = stack->map->arr[j];
// 			j--;
// 		}
// 		stack->map->arr[j + 1] = tmp;
// 		i++;
// 	}
// }

// void	insertion_sort(t_stack *stack)
// {
// 	ssize_t	i;
// 	ssize_t	j;

// 	i = 1;
// 	while (i < stack->a->count)
// 	{
// 		j = i - 1;
// 		if (stack->a->arr[1] > stack->a->arr[0])
// 			pb(stack->a, stack->b);
// 		else
// 			sa(stack->a);
// 		while (j >= 0 && stack->a->arr[1] > stack->a->arr[0])
// 		{
// 			pb(stack->a, stack->b);
// 			j--;
// 		}
// 		i++;
// 	}
// }

/// @brief makes a copy of the stack a and sorts it to find the max,
/// mid and min values. the map contains the pre sorted stack a.
/// @param stack the stack holder
// void	map(t_stack *stack)
// {
// 	ssize_t		i;

// 	i = 0;
// 	while(stack->a->count > i)
// 	{
// 		stack->map->arr[i] = stack->a->arr[i];
// 		i++;
// 	}
// 	stack->map->count = stack->a->count;
// 	insertion_sort1(stack);
// 	stack->map->max = stack->map->arr[stack->map->count - 1];
// 	stack->map->min = stack->map->arr[0];
// 	i = stack->map->count / 2;
// 	stack->map->mid = stack->map->arr[i];
// }

// void	insertion_sort(t_stack *stack)
// {
	// map(stack);
	// while (!sorted(stack))
	// {
	// 	while (stack->a->count > 1)
	// 	{
	// 		if (stack->a->arr[0] > stack->a->arr[stack->a->count - 1]
	// 			&& stack->a->arr[0] > stack->a->arr[1])
	// 			pb(stack->a, stack->b);
	// 		else if (stack->a->arr[0] > stack->a->arr[stack->a->count - 1])
	// 			ra(stack->a);
	// 		else if (stack->a->arr[0] > stack->a->arr[1])
	// 			sa(stack->a);
	// 		else
	// 			rra(stack->a);
	// 	}
	// }
// }
