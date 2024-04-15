/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahakala <mahakala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:46:54 by mahakala          #+#    #+#             */
/*   Updated: 2024/04/15 10:40:42 by mahakala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_insert(t_link ** sorted, t_link *new)
{
	t_link **current;

	current = sorted;
	while (*current != NULL && (*current)->num < new->num)
		current = &(*current)->next;
	new->next = *current;
	if (*current)
		new->prev = (*current);
	else
		new->prev = NULL;
	if (*current)
		(*current)->prev = new;
	if (new->prev)
		new->prev->next = new;
	else
		*sorted = new;
}

void	insertion_sort(t_link **a)
{
	t_link  *actual;
	t_link  *sorted;
	t_link  *next;

	sorted = NULL;
	actual = *a;
	while (actual  != NULL)
	{
		next = actual->next;
		actual->next = actual->prev = NULL;
		sorted_insert(&sorted, actual);
		actual = next;
	}
	*a = sorted;
}