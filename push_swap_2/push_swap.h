/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:06:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/10 12:53:29 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_link
{
	int				num;
	struct s_link	*next;
	struct s_link	*actual;
	struct s_link	*prev;
}	t_link;

void		error1(char **argv, int err_num);

///###################### Operations ################

///swap.c
void		sa(t_link *a);
void		sb(t_link *b);
void		ss(t_link *a, t_link *b);

///push.c
void		pa(t_link **a, t_link **b);
void		pb(t_link **a, t_link **b);

///rotate.c
void		ra(t_link *a);
void		rb(t_link *b);
void		rr(t_link *a, t_link *b);

///reverse_rotate.c
void		rra(t_link *a);
void		rrb(t_link *b);
void		rrr(t_link *a, t_link *b);

#endif