/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:05:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/17 22:28:05 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief copy the numbers from the split string to the stack and free the 
/// split string... and checks if its maybe only one number
/// @param stack holds the stacks a and b
/// @param numbers holds the split string
/// @param count number countet of the split string
static void	copy_free_numbers(t_stack *stack, char **numbers, int count)
{
	int		i;
	bool	wrong;

	i = 0;
	wrong = false;
	while (i < count)
	{
		stack->a->arr[i] = ft_ato_ssize_t(numbers[i]);
		if (numbers[i][0] == '-' && (numbers[i][1] < '0' || numbers[i][1] > '9'))
			wrong = true;
		if (stack->a->arr[i] < -2147483648 || stack->a->arr[i] > 2147483647)
			wrong = true;
		free(numbers[i]);
		i++;
	}
	if (wrong)
	{
		free(numbers);
		error3(stack, 3);
	}
	free(numbers);
}

/// @brief counts the numbers in the split string and checks if they are digits
/// wit ft_is_digit... saves the countet numbers in the stack_a_count and sets
/// the stack_b_count to 0... mallocs the needed memory for the stack_a.
/// @param argv 
/// @param stack 
void	str_c_to_ssize_t(char *argv, t_stack *stack)
{
	char		**numbers;
	int		count;

	numbers = ft_split(argv, ' ');
	if (!numbers)
		error3(stack, 0);
	count = 1;
	while (numbers[count])
	{
		if (ft_is_digit(numbers[count], stack))
			error3(stack, 8);
		count++;
	}
	if (stack->a->min == true)
		error3(stack, 1);
	stack->a->arr = malloc(sizeof(sizeof(ssize_t) + 1)  * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->a->count = count;
	stack->b->arr = malloc(sizeof(sizeof(ssize_t) + 1) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	copy_free_numbers(stack, numbers, count);
}

void	char_to_ssize_t(char **argv, t_stack *stack)
{
	ssize_t	i;
	int	count;

	stack->a->min = false;
	i = 1;
	count = 1;
	// if (!argv[1] || !argv[2])
	// 	error3(stack, 5);
	while (argv[count])
	{
		if (ft_is_digit(argv[count], stack))
			error3(stack, 1);
		count++;
	}
	if (stack->a->min == true)
		error3(stack, 3);
	stack->a->arr = malloc((sizeof(ssize_t) + 1) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->b->arr = malloc((sizeof(ssize_t) + 1) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	while (i < count)
	{
		stack->a->arr[i - 1] = ft_ato_ssize_t(argv[i]);
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

	stack = NULL;
	if (argc < 2 ||  !argv[1][0])
		return (0);
	init_stack(&stack);
	if (argc == 2)
		str_c_to_ssize_t(argv[1], stack);
	if (argc > 2)
		char_to_ssize_t(argv, stack);
	check_stack(stack);
	if (stack->a->count == 1 )
	{
		free_iter(stack);
		exit(EXIT_SUCCESS);
	}
	init_int(stack);
	init(stack);
	operation_cases(stack);
	free_iter(stack);
	return (0);
}

	// prssize_tf("stack->a->count: %d\n", stack->a->count);
	// i = 0;
	// while (i < stack->a->count)
	// {
	// 	prssize_tf("stack->a->arr[%d]: %d\n", i, stack->a->arr[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < stack->b->count)
	// {
	// 	prssize_tf("stack->b->arr[%d]: %d\n", i, stack->b->arr[i]);
	// 	i++;
	// }