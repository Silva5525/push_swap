/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:23:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/07 19:18:55 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_link **link)
{
	t_link	*a;
	t_link	*b;

	if (!*link || !(*link)->next || (*link) == (*link)->next)
		return ;

}
