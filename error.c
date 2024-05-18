/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:22:25 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 19:28:01 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief prints the error message and frees the stack with free_iter
/// @param stack holds the stacks a and b
/// @param err_num error number
void	error3(t_stack *stack, ssize_t err_num)
{
	if (err_num == -1)
		ft_write(2, "Error\n", 7);
	if (err_num == 10)
		ft_write(2, "Error\n", 7);
	if (err_num == 0)
		ft_write(2, "Error\n", 7);
	if (err_num == 1)
		ft_write(2, "Error\n", 7);
	if (err_num == 2)
		ft_write(2, "Error\n\n", 7);
	if (err_num == 3)
		ft_write(2, "Error\n", 7);
	if (err_num == 4)
		ft_write(2, "Error\n", 7);
	if (err_num == 5)
	{
		free_iter(stack);
		exit(EXIT_SUCCESS);
	}
	if (err_num == 8)
		ft_write(2, "Error\n", 6);
	free_iter(stack);
	exit(EXIT_FAILURE);
}

// void	error1(char **argv, int err_num)
// {
// 	char	**tmp;

// 	tmp = argv;
// 	if (err_num == 1)
// 		ft_write(2, "Error\n no or only one Number\n", 30);
// 	if (err_num == 8)
// 		ft_write(2, "Error\n \n", 24);
// 	while (*tmp)
// 	{
// 		free(*argv);
// 		argv--;
// 	}
// 	free(argv);
// 	exit(EXIT_FAILURE);
// }

// void	error2(char **argv, t_link **a, int err_num)
// {
// 	if (err_num == 2)
// 		ft_write(1, "Error\n only one number found.\n", 31);
// 	free_argv(argv);
// 	exit(EXIT_FAILURE);
// }

// void	error0(ssize_t err_num)
// {
// 	if (err_num == -1)
// 		ft_write(2, "Error\n Use ./push_swap \"1 2 3 .. \" OR 1 2 3..\n", 47);
// 	if (err_num == 0)
// 		ft_write(2, "Error\n first Malloc NULL\n", 26);
// 	if (err_num == 1)
// 		ft_write(2, "Error\n no or only one Number\n", 30);
// 	if (err_num == 8)
// 		ft_write(2, "Error\n found non Digit\n", 24);
// 	exit(EXIT_FAILURE);
// }
