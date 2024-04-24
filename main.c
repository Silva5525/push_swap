/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:32 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/24 16:58:48 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief checks if the stack has no duplicates, if it has duplicates it will
/// throw an error.
/// @param stack holder of the stacks
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

/// @brief initialize the stacks if argv are 2 arguments. Splits the string
/// ,counts it, and converts it to int and stores it in the stack a. Initializes
/// the oter stacks and gives it a count.
/// @param argv the values of the stack as chars
/// @param stack holder of the stack
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

/// @brief initialize the stacks if argv is more than 2 arguments, counts it,
/// converts the char to int and stores it in the stack a. Initializes the other
/// stacks and gives it a count.
/// @param argv the values of the stack as chars
/// @param stack the holder of the stack
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

/// @brief initialize the stack with malloc for the struct of a b and map
/// @param stack stack holder
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
