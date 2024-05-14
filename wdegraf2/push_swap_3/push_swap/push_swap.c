/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:30:58 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 13:26:03 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list *return_cheapest(t_link *b)
// {
// 	while (b)
// 	{
// 		if (b->cheapest)
// 			return (b);
// 		b = b->next;
// 	}
// 	return (NULL);
// }

void rr_all(t_link **a, t_link **b, t_link *tmp)
{
	while (*a != tmp->actual && *b != tmp)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void r_all(t_link **a, t_link **b, t_link *tmp)
{
	while (*a != tmp->actual && *b != tmp)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void finish_rotation(t_link **a, t_link *tmp, char name)
{
	while (*a != tmp)
	{
		if (name == 'a')
		{
			if (tmp->near)
				ra(a);
			else
				rra(a);
		}
		else if (name == 'b')
		{
			if (tmp->near)
				rb(a);
			else
				rrb(a);
		}
	}
}

static void move_noedes(t_link **a, t_link **b)
{
	t_link *tmp;
	
	tmp = *b;
	while (tmp)
	{
		if (tmp->cheapest)
			break ;
		tmp = tmp->next;
	}
	if (tmp->near || tmp->actual->near)
			r_all(a, b, tmp);
	else if (!tmp->near || !tmp->actual->near)
			rr_all(a, b, tmp);
	finish_rotation(b, tmp, 'b');
	finish_rotation(a, tmp->actual, 'a');
	pa(a, b);
}

void	set_cheapest(t_link *b)
{
	int i;
	t_link *tmp;
	
	i = INT_MAX;
	while (b)
	{
		if (b->far < i)
		{
			i = b->far;
			tmp = b;
		}
		b = b->next;
	}
	tmp->cheapest = true;
}

int	stack_len(t_link *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

static void set_target_node(t_link *a, t_link *b)
{
	t_link *tmp_a;
	t_link *tmp_b;
	ssize_t diff;

	while (b)
	{
		diff = INT_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->num > b->num && tmp_a->num < diff)
			{
				diff = tmp_a->num;
				tmp_b = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (diff == INT_MAX)
			b->actual = INT_MAX;
		else
			b->actual = tmp_b;
		b = b->next;
	}
}

void	set_price(t_link *a, t_link *b)
{
	int i;
	int j;

	i = stack_len(a);
	j = stack_len(b);
	while (b)
	{
		b->far = b->posi;
		if (!(b->near))
			b->far = j - b->posi;
		if (b->actual->near)
			b->far += b->actual->posi;
		else
			b->far += i - b->actual->posi;
		b = b->next;
	}
}

void	set_current_position(t_link *a)
{
	int i;
	int j;

	i = 0;
	j = stack_len(a) / 2;
	while (a)
	{
		a->posi = i;
		if (i <= j)
			a->near = true;
		else
			a->near = false;
		i++;
		a = a->next;
	}
}

void	init_nodes(t_link *a, t_link *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	push_swap(t_link **a, t_link **b)
{
	t_link	*tmp;
	int		i;
	
	i = ft_lstsize(*a);
	if(i == 5)
		sort_five(a, b);
	else
		while (i-- > 3)
			pb(a, b);
	sort_three(a);
	while (*b)
	{
		init_nodes(a, b);
		move_nodes(a, b);
	}
	set_current_position(a);
	tmp = find_smallest(*a);
	if (tmp->near)
	{
		while ((*a) != tmp)
			ra(a);
	}
	else
	{
		while ((*a) != tmp)
			rra(a);
	}
}