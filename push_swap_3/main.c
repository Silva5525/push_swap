/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:05:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/19 21:30:18 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(t_stack *stack)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < stack->a->count)
	{
		j = 0;
		while (j < stack->a->count)
		{
			if (stack->a->arr[i] == stack->a->arr[j] && i != j)
				error3(stack, 10);
			j++;
		}
		i++;
	}
}

void	str_c_to_int(char *argv, t_stack *stack)
{
	char	**numbers;
	int		i;
	int		count;

	numbers = ft_split(argv, ' ');
	if (!numbers)
		error1(numbers, 0);
	i = 0;
	count = 1;
	while (numbers[count])
		count++;
	stack->a->arr = malloc(sizeof(int) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->a->count = count;
	stack->b->arr = malloc(sizeof(int) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	stack->map->arr = malloc(sizeof(int) * count);
	if (!stack->map->arr)
		error3(stack, 0);
	stack->map->count = 0;
	while (i < count)
	{
		stack->a->arr[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	char_to_int(char **argv, t_stack *stack)
{
	int		i;
	int		count;

	i = 1;
	count = 1;
	while (argv[count])
		count++;
	stack->a->arr = malloc(sizeof(int) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->b->arr = malloc(sizeof(int) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	stack->map->arr = malloc(sizeof(int) * count);
	if (!stack->map->arr)
		error3(stack, 0);
	stack->map->count = 0;
	while (i < count)
	{
		stack->a->arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack->a->count = count - 1;
}

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		error0(0);
	(*stack)->a = malloc(sizeof(t_link));
	if (!(*stack)->a)
		error3(*stack, 0);
	(*stack)->b = malloc(sizeof(t_link));
	if (!(*stack)->b)
		error3(*stack, 0);
	(*stack)->map = malloc(sizeof(t_link));
	if (!(*stack)->map)
		error3(*stack, 0);
	
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
	{
		printf("1stack->a->arr[%d]: %d\n", i, stack->a->arr[i]);
		i++;
	}
	i = 0;
	if (!sorted(stack->a))
	{
		if (stack->a->count <= 3)
			sort_3(stack);
		// else
			// big_push_swap(stack);
		// else if (stack->a->count < 32)
		// 	insertion_sort(stack);
		// else
		// 	tim_sort(stack);
	}
	printf("stack->a->count: %d\n", stack->a->count);
	i = 0;
	while (i < stack->a->count)
	{
		printf("stack->a->arr[%d]: %d\n", i, stack->a->arr[i]);
		i++;
	}
	i = 0;
	while (i < stack->b->count)
	{
		printf("stack->b->arr[%d]: %d\n", i, stack->b->arr[i]);
		i++;
	}
	i = 0;
	while (i < stack->map->count)
	{
		printf("stack->map->arr[%d]: %d\n", i, stack->map->arr[i]);
		i++;
	}
	free_iter(stack);
	return (0);
}

	// if (!sorted(stack))
	// {
	// 	if (stack->a->next == NULL || a->next->next == NULL)
	// 		error3(stack, 11);
	// 	else if (a->next->next->next == NULL)
	// 		insertion_sort(stack);
	// 	else
	// 		tim_sort();
	// }