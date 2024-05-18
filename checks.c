/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:49:02 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 18:39:10 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	ft_is_digit(char *str, t_stack *stack)
{
	ssize_t	i;

	i = 0;
	(void)stack;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		stack->a->min = false;
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (i == 1 && str[0] == '-')
		stack->a->min = true;
	return (EXIT_SUCCESS);
}

void	check_stack(t_stack *stack)
{
	ssize_t	i;
	ssize_t	j;

	j = 0;
	i = 0;
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
