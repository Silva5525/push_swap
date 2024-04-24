/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:59:06 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/24 16:59:16 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

/// @brief struct to hold the informations
/// arr: the array of the stack
/// count: the count of the stack
/// max: the max value of the stack
/// mid: the midle value of the stack
/// min: the minimum value of the stack
typedef struct s_link
{
	int				*arr;
	int				count;
	int				max;
	int				mid;
	int				min;
}	t_link;

/// @brief struct to hold the stacks
/// a: the stack a 
/// b: the stack b
/// map: the map which will be sorted before the push_swap
typedef struct s_stacks
{
	t_link	*a;
	t_link	*b;
	t_link	*map;
}	t_stack;

/// error.c
void		error0(int err_num);
void		error1(char **argv, int err_num);
// void		error2(char **argv, int err_num);
void		error3(t_stack *stack, int err_num);
void		free_iter(t_stack *stack);

#endif