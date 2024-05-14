/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:25:20 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 12:31:10 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

// typedef struct s_lister
// {
// 	struct s_link	*head;
// 	struct s_link	*tail;
// } t_lister;

typedef struct s_link
{
	bool 			cheapest;
	bool 			near;
	int 			far;
	int 			index;
	int				num;
	int				posi;
	struct s_link	*prev;
	struct s_link	*actual;
	struct s_link	*next;
} t_link;

//first_utils.c
void 	ft_double_list(t_link **a, int num);
int		if_sorted(t_link *a);
///exit_manager.c
int 	if_dubplicate(t_link *a, int num);
void	free_argv(char **argv);
void	free_t_link(t_link **a);
void	ft_free(t_link **a, char **argv, int argc);
void	error(int error_code, t_link *a, char **argv, int argc);
///push_swap.c
void	push_swap(t_link **a, t_link **b);
void	init_nodes(t_link *a, t_link *b);
void	set_cheapest(t_link *b);
int		stack_len(t_link *a);
void	set_target_node(t_link *a, t_link *b);
void	set_current_position(t_link *a);
///sort.c
void 	sort_three(t_link **a);
void 	sort_five(t_link **a, t_link **b);
t_link	*find_smallest(t_link *a);
t_link	*find_max(t_link *a);
void	finish_rotation(t_link **a, t_link *node, char name);
///reverse_rotation.c
void	rra(t_link **a);
void	rrb(t_link **b);
void	rrr(t_link **a, t_link **b);
///rotation.c
void	ra(t_link **a);
void	rb(t_link **b);
void	rr(t_link **a, t_link **b);
///sort.c
void	sa(t_link **a);
void	sb(t_link **b);
void	ss(t_link **a, t_link **b);
///push.c
void	pa(t_link **a, t_link **b);
void	pb(t_link **a, t_link **b);

#endif