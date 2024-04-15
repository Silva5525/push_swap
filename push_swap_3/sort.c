/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:46:54 by mahakala          #+#    #+#             */
/*   Updated: 2024/04/15 18:59:47 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->a->count - 1)
	{
		if (stack->a->arr[i] > stack->a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	insertion_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < stack->a->count)
	{
		tmp = stack->a->arr[i];
		j = i - 1;
		while (j >= 0 && stack->a->arr[j] > tmp)
		{
			stack->a->arr[j + 1] = stack->a->arr[j];
			j--;
		}
		stack->a->arr[j + 1] = tmp;
		i++;
	}
}

