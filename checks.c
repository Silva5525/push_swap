/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:49:02 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/12 16:09:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}


void	check_stack(t_stack *stack)
{
	int	i;
	int	j;

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
