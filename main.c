/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:05:44 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 14:49:49 by wdegraf          ###   ########.fr       */
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
		if ((numbers[i][0] == '-' && (numbers[i][1] < '0'
			|| numbers[i][1] > '9')) || numbers[i][0] == '+')
			wrong = true;
		if (stack->a->arr[i] < INT_MIN || stack->a->arr[i] > INT_MAX)
			wrong = true;
		free(numbers[i]);
		i++;
	}
	if (wrong)
	{
		free(numbers);
		error3(stack, 4);
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
	size_t		count;

	numbers = ft_split(argv, ' ');
	if (!numbers)
		error3(stack, 0);
	count = 0;
	while (numbers[count])
	{
		if (ft_is_digit(numbers[count], stack))
			error3(stack, 8);
		count++;
	}
	if (stack->a->min == true)
		error3(stack, 1);
	stack->a->arr = malloc(sizeof(ssize_t) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->a->count = count;
	stack->b->arr = malloc(sizeof(ssize_t) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	copy_free_numbers(stack, numbers, count);
}

/// @brief changes the char numbers to ssize_t and saves them in the stack_a
/// while checking for INT_MIN and INT_MAX.
/// @param argv 
/// @param stack 
void	char_copy(char **argv, t_stack *stack)
{
	ssize_t		i;

	i = 1;
	while (i < (stack->a->count + 1))
	{
		stack->a->arr[i - 1] = ft_ato_ssize_t(argv[i]);
		if (stack->a->arr[i - 1] < INT_MIN
			|| stack->a->arr[i - 1] > INT_MAX)
			error3(stack, 4);
		i++;
	}
}

/// @brief counts the numbers of argv and checks if they are digits with
/// ft_is_digit then allocates the needed memory for the stack_a and stack_b
/// and saves the numbers in the stack_a with char_copy.
/// @param argv the arguments
/// @param stack holder of the stack
void	char_to_ssize_t(char **argv, t_stack *stack)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 1;
	while (argv[count])
	{
		if (ft_is_digit(argv[count], stack))
			error3(stack, 1);
		count++;
	}
	if (stack->a->min == true)
		error3(stack, 3);
	stack->a->arr = malloc((sizeof(ssize_t)) * count);
	if (!stack->a->arr)
		error3(stack, 0);
	stack->a->count = count - 1;
	stack->b->arr = malloc((sizeof(ssize_t)) * count);
	if (!stack->b->arr)
		error3(stack, 0);
	stack->b->count = 0;
	char_copy(argv, stack);
}

/// @brief Initializes the stack and checks if the arguments are valid
/// and if the stack struct with malloc sends the stack to the sorting
/// functions and frees the stack after using it
/// @param stack the stack holder for the stack a and b
/// @param argc the argument counted
/// @param argv the arguments
/// @return 0 if the program ends or nothing is to sort.
/// else the program will sort the stack and return 0
int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	init_stack(&stack);
	if (argc == 2)
		str_c_to_ssize_t(argv[1], stack);
	if (argc > 2)
		char_to_ssize_t(argv, stack);
	check_stack(stack);
	if (stack->a->count == 1)
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
