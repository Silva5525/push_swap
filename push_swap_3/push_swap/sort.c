/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:05:10 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/27 21:11:04 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_link **a, t_link *node, char name)
{
	while (*a != node)
	{
		if (name == 'a')
		{
			if (node->near)
				ra(a);
			else
				rra(a);
		}
		else if (name == 'b')
		{
			if (node->near)
				rb(a);
			else
				rrb(a);
		}
	}
}

t_link *find_smallest(t_link *a)
{
	int mini;
	t_link *min;

	mini = INT_MAX;
	while (a)
	{
		if (a->num < mini)
		{
			mini = a->num;
			min = a;
		}
		a = a->next;
	}

	return (min);
}

static t_link *find_max(t_link *a)
{
	int maxi;
	t_link *max;

	maxi = INT_MIN;
	while (a)
	{
		if (a->num > maxi)
		{
			maxi = a->num;
			max = a;
		}
		a = a->next;
	}

	return (max);
}

void sort_five(t_link **a, t_link **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(a, b);
	}
}

void sort_three(t_link **a)
{
	t_link *tmp;

	tmp = find_max(*a);
	if (*a == tmp)
		ra(a);
	else if ((*a)->next == tmp)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}