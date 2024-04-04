/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:05:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/04 11:57:13 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error1(char **argv, int err_num)
{
	if (err_num == 1)
		ft_write(2, "Error\n duplicated number found.\n", 35);
	free_argv(argv);
	exit(EXIT_FAILURE);
}

void double_list(t_link **a, int num)
{
	
}

void	check_stack(t_link *a, char **argv, int argc)
{
	ssize_t	num;
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			error1(argv, 2);
		while (a)
		{
			if (a->num == num)
				error1(argv, 1);
			a = a->next;
		}
		double_list()
		i++;
	}
	if (argc == 2)
		free_argv(argv);
}

int	main(int argc, char **argv)
{
	t_link	*a;
	t_link	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
	{
		ft_write(2, "Error\n Use ./push_swap \"1 2 3 .. \" OR 1 2 3..\n", 47);
		return (1);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	check_stack(&a, argv, argc);
	return (0);
}
