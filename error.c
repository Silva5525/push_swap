/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:45:40 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/24 16:58:51 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief free the t_stack and its t_link a and b and the t_map arrays.
/// @param stack holder of the stacks
void	free_iter(t_stack *stack)
{
	if (stack->a->arr != NULL)
	{
		free(stack->a->arr);
		stack->a->arr = NULL;
		free(stack->a);
	}
	if (stack->b->arr != NULL)
	{
		free(stack->b->arr);
		stack->b->arr = NULL;
		free(stack->b);
	}
	if (stack->map->arr != NULL)
	{
		free(stack->map->arr);
		stack->map->arr = NULL;
		free(stack->map);
	}
	free(stack);
}


/// @brief exit the program with EXIT_FAILURE and write the error message
/// with freeing anything. 
/// @param err_num the write error number
void	error0(int err_num)
{
	if (err_num == -1)
		ft_write(2, "Error\n Use ./push_swap \"1 2 3 .. \" OR 1 2 3..\n", 47);
	if (err_num == 0)
		ft_write(1, "Error\n first Malloc NULL\n", 26);
	exit(EXIT_FAILURE);
}

/// @brief free the argv and exit the program with EXIT_FAILURE
/// @param argv holder of the values of the stack as chars
/// @param err_num the write error number
void	error1(char **argv, int err_num)
{
	if (err_num == 1)
		ft_write(1, "Error\n str_c_to_int for ft_split.\n", 35);
	while (*argv)
	{
		free(*argv);
		argv++;
	}
	free(argv);
	exit(EXIT_FAILURE);
}

// void	error2(char **argv, t_link **a, int err_num)
// {
// 	if (err_num == 2)
// 		ft_write(1, "Error\n only one number found.\n", 31);
// 	free_argv(argv);
// 	exit(EXIT_FAILURE);
// }


/// @brief frees the stack and exits the program with EXIT_FAILURE
/// @param stack stack holder
/// @param err_num the write error number
void	error3(t_stack *stack, int err_num)
{
	if (err_num == 10)
		ft_write(1, "Error\n Double Number\n", 22);
	if (err_num == 0)
		ft_write(1, "Error\n Malloc fail\n", 20);
	free_iter(stack);
	exit(EXIT_FAILURE);
}
