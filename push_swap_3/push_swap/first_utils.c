/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:13:12 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/27 17:27:58 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_double_list(t_link **a, int num)
{
	t_link	*node;
	t_link	*tmp;

	if (!a)
		return ;
	node = malloc(sizeof(t_link));
	if (!node)
		error(3 , a, NULL, 0);
	node->num = num;
	node->next = NULL;
	if (!*a)
	{
		node->prev = NULL;
		*a = node;
	}
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
}

int	if_sorted(t_link *a)
{
	t_link	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void	ft_double_list(t_lister *list, int num)
// {
// 	t_link	*node;

// 	if(!list)
// 		return ;
// 	node = malloc(sizeof(t_link));
// 	if (!node)
// 		error(3);
// 	node->num = num;
// 	node->next = NULL;
// 	node->prev = list->tail;
// 	if (list->tail)
// 		list->tail->next = node;
// 	else
// 		list->head = node;
// 	list->tail = node;
// }