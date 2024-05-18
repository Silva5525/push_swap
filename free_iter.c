/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:34:11 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 12:37:23 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free4(t_stack *stack)
{
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
	if (stack->b->arr != NULL)
	{
		free(stack->b->arr);
		stack->b->arr = NULL;
	}
}

static void	free3(t_stack *stack)
{
	if (stack->a->midle != NULL)
	{
		free(stack->a->midle);
		stack->a->midle = NULL;
	}
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
}

static void	free2(t_stack *stack)
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
	if (stack->a->arr != NULL)
	{
		free(stack->a->arr);
		stack->a->arr = NULL;
	}
}

void	free_iter(t_stack *stack)
{
	free2(stack);
	free3(stack);
	free4(stack);
	if (stack->a != NULL)
	{
		free(stack->a);
		stack->a = NULL;
	}
	if (stack->b != NULL)
	{
		free(stack->b);
		stack->b = NULL;
	}
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}
