/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:05:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/10 11:47:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error1(char **argv, int err_num)
{
	if (err_num == 1)
		ft_write(1, "Error\n duplicated number found.\n", 35);
	free_argv(argv);
	exit(EXIT_FAILURE);
}

void	error2(char **argv, t_link **a, int err_num)
{
	if (err_num == 2)
		ft_write(1, "Error\n only one number found.\n", 31);
	free_argv(argv);
	exit(EXIT_FAILURE);
}

void	double_list(t_link **a, int num)
{
	t_link	*new;
	t_link	*current;

	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	if (!*a)
		*a = new;
	else
	{
		current = *a;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
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
		double_list(a, num);
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
	if (!sorted(a))
	{
		if (a->next == NULL)
			error1(argv, &a, 2)
		else if (a->next->next == NULL);
			
	}
	return (0);
}
