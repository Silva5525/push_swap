/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:46:54 by mahakala          #+#    #+#             */
/*   Updated: 2024/04/24 15:31:31 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief checks if the list is sorted in ascending order
/// @param stack is the struct holder of the stack a and b but it checks only a
/// @return 1 if the list is sorted, 0 if not
int	sorted(t_link *stack)
{
	int	i;

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
	if (stack->a->count == 2)
	{
		if (stack->a->arr[0] > stack->a->arr[1])
			sa(stack->a);
		return ;
	}
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
void	insertion_sort1(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < stack->map->count)
	{
		tmp = stack->map->arr[i];
		j = i - 1;
		while (j >= 0 && stack->map->arr[j] > tmp)
		{
			stack->map->arr[j + 1] = stack->map->arr[j];
			j--;
		}
		stack->map->arr[j + 1] = tmp;
		i++;
	}
}

// void	insertion_sort(t_stack *stack)
// {
// 	int	i;
// 	int	j;

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

void	map(t_stack *stack)
{
	int		i;

	i = 0;
	while(stack->a->count > i)
	{
		stack->map->arr[i] = stack->a->arr[i];
		i++;
	}
	stack->map->count = stack->a->count;
	insertion_sort1(stack);
	stack->map->max = stack->map->arr[stack->map->count - 1];
	stack->map->min = stack->map->arr[0];
	i = stack->map->count / 2;
	stack->map->mid = stack->map->arr[i];
	printf("max[%d] = %d\n", i, stack->map->max);
	printf("mid[%d] = %d\n", i, stack->map->mid);
	printf("min[%d] = %d\n", i, stack->map->min);
}

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

// int main() 
// {
//     int numbers[] = {10, 20, -50, -30, 40, 50};
//     t_stack myStack;
//     myStack->a->arr = numbers;
//     myStack->count = sizeof(numbers) / sizeof(numbers[0]);

//     int inBetweenValue = find_in_between(&myStack);
//     if (inBetweenValue != -1) {
//         printf("An in-between value in the stack is: %d\n", inBetweenValue);
//     } else {
//         printf("No in-between value found (stack may have too few distinct elements).\n");
//     }

//     return 0;
// }