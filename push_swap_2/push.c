/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:58:30 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/06 18:01:55 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_link **dst, t_link **src)
{
	t_link	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!*dst)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}
