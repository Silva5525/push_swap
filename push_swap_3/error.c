/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:22:25 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/12 16:56:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free3(t_stack *stack)
{
	if (stack->b->pos != NULL)
	{
		free(stack->b->pos);
		stack->b->pos = NULL;
	}
	if (stack->b->distance != NULL)
	{
		free(stack->b->distance);
		stack->b->distance = NULL;
	}
	if (stack->b->goal != NULL)
	{
		free(stack->b->goal);
		stack->b->goal = NULL;
	}
	if (stack->b->nearest != NULL)
	{
		free(stack->b->nearest);
		stack->b->nearest = NULL;
	}
	if (stack->b->midle != NULL)
	{
		free(stack->b->midle);
		stack->b->midle = NULL;
	}
}

void	free2(t_stack *stack)
{
	if (stack->a->pos != NULL)
	{
		free(stack->a->pos);
		stack->a->pos = NULL;
	}
	if (stack->a->distance != NULL)
	{
		free(stack->a->distance);
		stack->a->distance = NULL;
	}
	if (stack->a->goal != NULL)
	{
		free(stack->a->goal);
		stack->a->goal = NULL;
	}
	if (stack->a->nearest != NULL)
	{
		free(stack->a->nearest);
		stack->a->nearest = NULL;
	}
	if (stack->a->midle != NULL)
	{
		free(stack->a->midle);
		stack->a->midle = NULL;
	}
}

void	free_iter(t_stack *stack)
{
	free2(stack);
	free3(stack);
	if (stack->a->arr != NULL)
	{
		free(stack->a->arr);
		stack->a->arr = NULL;
	}
	free(stack->a);
	if (stack->b->arr != NULL)
	{
		free(stack->b->arr);
		stack->b->arr = NULL;
	}
	free(stack->b);
	free(stack);
}

void	error1(char **argv, int err_num)
{
	if (err_num == 1)
		ft_write(2, "Error\n str_c_to_int for ft_split.\n", 35);
	if (err_num == 8)
		ft_write(2, "Error\n found non Digit\n", 24);
	while (*argv)
	{
		free(*argv);
		argv++;
	}
	free(argv);
	exit(EXIT_FAILURE);
}

// void	error2(char **argv, t_link **a, int err_num)
// {
// 	if (err_num == 2)
// 		ft_write(1, "Error\n only one number found.\n", 31);
// 	free_argv(argv);
// 	exit(EXIT_FAILURE);
// }

void	error3(t_stack *stack, int err_num)
{
	if (err_num == 10)
		ft_write(2, "Error\n Double Number\n", 22);
	if (err_num == 0)
		ft_write(2, "Error\n Malloc fail\n", 20);
	if (err_num == 1)
		ft_write(2, "Error\n Malloc fail\n", 20);
	if (err_num == 2)
		ft_write(2, "Error\n sorted\n", 15);
	if (err_num == 8)
		ft_write(2, "Error\n found non Digit or non INT\n", 35);
	free_iter(stack);
	exit(EXIT_FAILURE);
}
