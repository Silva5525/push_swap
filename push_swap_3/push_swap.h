/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:06:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/15 18:33:48 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_link
{
	int				*arr;
	int				count;
	// int				num;
	// int				*next;
	// int				*actual;
	// int				*prev;
	// bool			zero;
}	t_link;

typedef struct s_stacks
{
	t_link	*a;
	t_link	*b;
}	t_stack;

/// error.c
void		error0(int err_num);
void		error1(char **argv, int err_num);
// void		error2(char **argv, int err_num);
void		error3(t_stack *stack, int err_num);
void		free_iter(t_stack *stack);

/// sort.c
int		sorted(t_stack *stack);
void	insertion_sort(t_stack *stack);

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