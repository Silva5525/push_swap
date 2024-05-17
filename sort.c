/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:46:54 by mahakala          #+#    #+#             */
/*   Updated: 2024/05/11 12:14:49 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// is not correct
void	rotations_b(t_stack *stack)
{
	ssize_t	near_pos;
	ssize_t	target;

	near_pos = get_nearest(stack->b);
	target = stack->b->arr[near_pos];
	while (stack->b->arr[0] != target)
	{
		if (near_pos < (stack->a->count / 2))
			rb(stack->b);
		else
			rrb(stack->b);
	}
}

/// 
void	rotations_a(t_stack *stack)
{
	ssize_t	near_pos;
	ssize_t	goal;
	ssize_t	target;

	near_pos = get_nearest(stack->b);
	goal = stack->b->goal[near_pos];
	target = stack->a->arr[goal];
	while (stack->a->arr[0] != target)
	{
		if (near_pos < (stack->a->count / 2))
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

// /// is not correct
// void	rotations_a(t_stack *stack)
// {
// 	ssize_t hold;
// 	ssize_t min;
// 	init(stack);
// 	min = get_nearest(stack->b);
// 	hold = min;
// 	prssize_tf("hold = %d\n", min);
// 	while (stack->a->arr[0] != hold)
// 	{
// 		prssize_tf("hold = %d\n", min);
// 		prssize_tf("b->goal[hold] = %d\n", stack->b->goal[hold]);
// 		prssize_tf("b->midle[hold] = %d\n", stack->b->midle[hold]);
// 		prssize_tf("a->distance[hold] = %d\n", stack->b->distance[hold]);
// 		prssize_tf("a->pos[hold] = %d\n", stack->b->pos[hold]);
// 		prssize_tf("b->nearest[hold] = %d\n", stack->b->nearest[hold]);	
// 		prssize_tf("rotate arr[0] = %d\n min a = %d\n", stack->b->arr[0], hold);
// 		if (stack->a->midle[hold])
// 			ra(stack->a);
// 		else
// 			rra(stack->a);
// 		init(stack);
// 	}
// }

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

// ssize_t main() 
// {
//     ssize_t numbers[] = {10, 20, -50, -30, 40, 50};
//     t_stack myStack;
//     myStack->a->arr = numbers;
//     myStack->count = sizeof(numbers) / sizeof(numbers[0]);

//     ssize_t inBetweenValue = find_in_between(&myStack);
//     if (inBetweenValue != -1) {
//         prssize_tf("An in-between value in the stack is: %d\n", inBetweenValue);
//     } else {
//         prssize_tf("No in-between value found (stack may have too few distinct
// elements).\n");
//     }

//     return 0;
// }