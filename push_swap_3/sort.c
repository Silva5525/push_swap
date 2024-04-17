/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:46:54 by mahakala          #+#    #+#             */
/*   Updated: 2024/04/17 17:44:34 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief checks if the list is sorted in ascending order
/// @param stack is the struct holder of the stack a and b but it checks only a
/// @return 1 if the list is sorted, 0 if not
int	sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->a->count)
	{
		if (stack->a->arr[i] > stack->a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/// @brief insertion_sort sorts the list by taking the first element and 
/// comparing it with the next element. If the next element is smaller than
/// the first element, the next element is inserted at the right position.
/// @param stack is the struct holder of the stack a and b but it sorts only a
// void	insertion_sort(t_stack *stack)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = 1;
// 	while (i < stack->a->count)
// 	{
// 		tmp = stack->a->arr[i];
// 		j = i - 1;
// 		while (j >= 0 && stack->a->arr[j] > tmp)
// 		{
// 			stack->a->arr[j + 1] = stack->a->arr[j];
// 			j--;
// 		}
// 		stack->a->arr[j + 1] = tmp;
// 		i++;
// 	}
// }

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

void	insertion_sort(t_stack *stack)
{
	while (stack->a->count > 0)
	{
		if (stack->a->arr[1] > stack->a->arr[0])
			pb(stack->a, stack->b);
		else
		{
			sa(stack->a);
			pb(stack->a, stack->b);
		}
		while ()
	}
}