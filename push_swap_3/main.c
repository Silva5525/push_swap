/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:05:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/12 17:32:37 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_numbers(char **numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	str_c_to_int(char *argv, t_stack *stack)
{
	char	**numbers;
	int		count;
	int		i;

	i = 0;
	numbers = ft_split(argv, ' ');
	if (!numbers)
		error1(numbers, 0);
	count = 1;
	while (numbers[count])
	{
		if (!ft_is_digit(numbers[count]))
			error1(numbers, 8);
		count++;
	}
	stack->a->arr = malloc(sizeof(int) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->a->count = count;
	stack->b->arr = malloc(sizeof(int) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	while (i < count)
	{
		stack->a->arr[i] = ft_atoi(numbers[i]);
		i++;
	}
	free_numbers(numbers, count);
}

void	char_to_int(char **argv, t_stack *stack)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	while (argv[count])
	{
		if (!ft_is_digit(argv[count]))
			error1(argv, 8);
		count++;
	}
	stack->a->arr = malloc((sizeof(int) + 1) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->b->arr = malloc((sizeof(int) + 1) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	while (i < count)
	{
		stack->a->arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack->a->count = count - 1;
}

static	void	operation_cases(t_stack *stack)
{
	if (stack->a->count == 2)
	{
		if (stack->a->arr[0] > stack->a->arr[1])
			sa(stack->a);
	}
	else if (stack->a->count == 3)
		sort_3(stack);
	else if (stack->a->count <= 7)
		push_swap_7(stack);
	else if (stack->a->count > 7)
		push_swap(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	if (argc < 2 || !argv[1][0])
		error0(-1);
	init_stack(&stack);
	if (argc == 2)
		str_c_to_int(argv[1], stack);
	if (argc > 2)
		char_to_int(argv, stack);
	check_stack(stack);
	while (i < stack->a->count)
		i++;
	i = 0;
	init_int(stack);
	init(stack);
	operation_cases(stack);
	free_iter(stack);
	return (0);
}

	// printf("stack->a->count: %d\n", stack->a->count);
	// i = 0;
	// while (i < stack->a->count)
	// {
	// 	printf("stack->a->arr[%d]: %d\n", i, stack->a->arr[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < stack->b->count)
	// {
	// 	printf("stack->b->arr[%d]: %d\n", i, stack->b->arr[i]);
	// 	i++;
	// }