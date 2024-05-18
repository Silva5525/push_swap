/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:06:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 13:36:08 by wdegraf          ###   ########.fr       */
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
	ssize_t		*arr;
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

/// push_swap.c
void			push_swap_7(t_stack *stack);
ssize_t			get_nearest(t_link *stack);

/// utils.c
ssize_t			min_i(t_link *stack);
void			init(t_stack *stack);
void			init_int(t_stack *stack);
void			check_position(t_link *stack);

/// error.c
void			error3(t_stack *stack, ssize_t err_num);

/// checks.c
ssize_t			ft_is_digit(char *str, t_stack *stack);

// void		error2(char **argv, ssize_t err_num);

void			free_iter(t_stack *stack);

/// sort.c
void			rotations_a(t_stack *stack);
void			rotations_b(t_stack *stack);
ssize_t			sorted(t_link *stack);
void			sort_3(t_stack *stack);
void			rotations_7(t_stack *stack);

/// init.c
void			push_swap(t_stack *stack);
void			check_stack(t_stack *stack);
void			init_stack(t_stack **stack);
void			operation_cases(t_stack *stack);

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

// README.md

// /// @brief initializes the values needet for sorting
// /// @param stack holder of the stack
// init(t_stack *stack);

// /// @brief checks the position of the elements in the stack and sets under
// /// the midle of the stack to true and the above to false
// /// @param stack->pos[i] a/b the position of the elements in the stack
// /// @param stack->midle[i] a/b true or false if the element is under or
// /// above the midle
// check_position(t_link *a/b);

// /// @brief it finds the smallest element in a that is still larger than 
// /// the given element in b  
// /// @param a stack a /// not used
// /// @param b->goal[i] is the smallest element in a that is still 
// /// larger than the given element in b
// /// the finish position of the element in stack a
// /// if not foundsets the goal to the position of the smallest element in a
// static void give_position(t_link *a, t_link *b);

// /// @param b->distance[i]  the distance of the element to the goal
// void	count_distance(t_link *a, t_link *b);

// /// @brief gives the nearest element for the b stack to push it
// /// checks the lowest b->distance
// /// @param b->nearest[i] is true if the element is the 
// /// nearest all other are false
// /// @param a stack a /// not used
// void	give_nearest(t_link *b);

// /// @brief finds the position of the smallest element in the 
/// //stack and saves it in stack->min
// /// @param stack->min the smallest int in the stack
// /// @return @param position of the smallest element
// int	find_min(t_link *stack);

// /// @brief searches the position of the nearearest element
// /// in stack a. puts the target on the
// /// element it holds and rotates it up if it is under the midle
// /// or down if it is above the midle
// /// @param stack holds the stack
// void	rotations_b(t_stack *stack);

// values :

// /// @param stack->min is the smallest int in the stack can 
// ///be set in a and in b
// /// @param stack->pos[i] a/b the position of the elements in the stack
// /// @param b->distance[i]  the distance (count of moves) of the element
// to the goal
// /// @param b->goal[i] is the smallest element in a that is still 
// /// larger than the given element in b
// /// the finish position of the element in stack a
// /// if not foundsets the goal to the position of the smallest element in a
// /// @param b->nearest[i] is true if the element is the nearest all other
// are false
// /// @param stack->midle[i] a/b true or false if the element is under
//  or above the 
// midlebrief sets the distance of the elements in the stack between the goal
// /// and the element which will be pushed
// /// @param a stack a /// not used
// /// @param b->distance[i]  the distance of the element to the goal
// void	count_distance(t_link *a, t_link *b);

// /// @brief gives the nearest element for the b stack to push it checks 
// the lowest b->distance
// /// @param b->nearest[i] is true if the element is the nearest all
// other are false
// /// @param a stack a /// not used
// void	give_nearest(t_link *b);

// /// @brief finds the position of the smallest element in the stack and
// saves it in stack->min
// /// @param stack->min the smallest int in the stack
// /// @return @param position of the smallest element
// int	find_min(t_link *stack);

// /// @brief searches the position of the nearearest element in stack a.
// puts the target on the
// /// element it holds and rotates it up if it is under the midle or
// down if it is above the midle
// /// @param stack holds the stack
// void	rotations_b(t_stack *stack);

// values :

// /// @param stack->min is the smallest int in the stack can be set
// in a and in b
// /// @param stack->pos[i] a/b the position of the elements in the stack
// /// @param b->distance[i]  the distance (count of moves) of the element
// to the goal
// /// @param b->goal[i] is the smallest element in a that is still 
// /// larger than the given element in b
// /// the finish position of the element in stack a
// /// if not foundsets the goal to the position of the smallest element in a
// /// @param b->nearest[i] is true if the element is the nearest all
// other are false
// /// @param stack->midle[i] a/b true or false if the element is under
// or above the midle
