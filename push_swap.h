/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:06:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/17 20:31:14 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

/// @brief struct to hold the stack a and b
/// @param arr * is the array of the stack
/// @param count is the number of elements in the stack (allways aktuell)
/// @param max is the biggest element in the stack (aktuell on the begining)
/// @param mid is the middle element in the stack (aktuell on the begining)
/// @param min is the smallest element in the stack (aktuell on the begining)

/// (aktuell after each init(stack))
/// @param pos * is a arr of the position of each ssize_t in arr in the stack
/// @param distance * is the distance of each element to the nearest
/// element in the other stack
/// @param goal * is the position of each element in the other stack
/// manly of b in a
/// @param nearest * is a bool arr to mark the nearest element in the
/// other stack
/// @param midle * is a bool arr to mark under the middle element in the stack
/// and false if it is above
typedef struct s_link
{
	ssize_t	*arr;
	ssize_t		count;
	ssize_t		min;
	ssize_t		*pos;
	ssize_t		*distance;
	ssize_t		*goal;
	bool		*nearest;
	bool		*midle;
}	t_link;

/// (aktuell after each init(stack))
/// @param pos *ssize_t ist die position von jedem ssize_t in arr im stack
/// @param distance *ssize_t ist der schrittzeahler der notigen bewegungen um
/// das element im nachbar stack zu platzieren
/// @param goal *ssize_t ist die position an dem dieses element im anderen
/// stack hin soll
/// @param nearest *bool markiert das die wenigsten schritte zu seinem
/// partner braucht
/// @param midle *bool ist war wenn das element unterhalb der mitte des
/// stacks ist und false wenn es oberhalb ist
typedef struct s_stacks
{
	t_link	*a;
	t_link	*b;
}	t_stack;

/// sort_master_10k.c
void			push_swap_7(t_stack *stack);
ssize_t			get_nearest(t_link *stack);

/// utils.c
ssize_t			min_i(t_link *stack);
void			init(t_stack *stack);
void			init_int(t_stack *stack);
void			check_position(t_link *stack);

/// error.c
void			error0(ssize_t err_num);
// void			error1(t_stack *stack, ssize_t err_num);
void			error3(t_stack *stack, ssize_t err_num);

/// checks.c
ssize_t			ft_is_digit(char *str, t_stack *stack);

// void		error2(char **argv, ssize_t err_num);

void			free_iter(t_stack *stack);

/// sort.c
void			rotations_a(t_stack *stack);
void			rotations_b(t_stack *stack);
ssize_t			sorted(t_link *stack);
// void			insertion_sort1(t_stack *stack);
void			sort_3(t_stack *stack);
void			rotations_7(t_stack *stack);

/// push_swap.c
void			push_swap(t_stack *stack);
void			check_stack(t_stack *stack);
void			init_stack(t_stack **stack);

///###################### Operations ################

///swap.c
void			sa(t_link *a);
void			sb(t_link *b);
void			ss(t_link *a, t_link *b);

///push.c
void			pa(t_link *a, t_link *b);
void			pb(t_link *a, t_link *b);

///rotate.c
void			ra(t_link *a);
void			rb(t_link *b);
void			rr(t_link *a, t_link *b);

///reverse_rotate.c
void			rra(t_link *a);
void			rrb(t_link *b);
void			rrr(t_link *a, t_link *b);

#endif