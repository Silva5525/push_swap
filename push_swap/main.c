/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:02:28 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 13:39:13 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_stack(t_link **a, char **argv, int argc)
{
	ssize_t			num;
	int				i;

	i = 0;
	while (argv[i] != NULL)
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX
			|| if_dubplicate(*a, (int)num))
			error(3, *a, argv, argc);
		ft_double_list(a, num);
		i++;
	}
	if (argc == 2)
		free_argv(argv);
}


int	main(int argc, char **argv)
{
	t_link	*a;
	t_link	*b;
	char	**splargv;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return(-1);
	splargv = ft_split(argv[1], ' ');
	do_stack(&a, splargv, argc);
	if (!if_sorted(a))
	{
		if (a->next == NULL)
			error(3, a, splargv, argc);
		else if (a->next->next == NULL)
			sa(&a);
		else if (a->next->next->next == NULL)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_t_link(&a);
	return (0);
}
