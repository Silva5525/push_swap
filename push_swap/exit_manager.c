/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:26:16 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/27 17:25:14 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

void	free_t_link(t_link **a)
{
	t_link	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	*a = NULL;
}

void	ft_free(t_link **a, char **argv, int argc)
{
	free_t_link(a);
	if (argc == 2)
		free_argv(argv);
	exit(EXIT_FAILURE);
}

void	error(int error_code, t_link *a, char **argv, int argc)
{
	if (error_code == 1)
		ft_write(1, "Error\nft_strcword count 0 or malloc error\n", 37);
	else
	{
		if (error_code == 3)
		ft_write(1, "Error\ndo_stack failed\n", 23);
		ft_free(&a, argv, argc);
	}
	exit(EXIT_FAILURE);
}

int if_dubplicate(t_link *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == num)
			return (1);
		a = a->next;
	}
	return (0);
}