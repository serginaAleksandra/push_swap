/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:43 by asergina          #+#    #+#             */
/*   Updated: 2025/11/20 05:40:32 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_stack	**a, t_stack **b)
{
	write(1, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}

int	stack_is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

static void	sorting(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a, b);
	else if (size == 3)
		sort_three(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		param_processing(&a, &b, argv, argc);
		if (!a)
			exit_with_error(&a, &b);
		size = lstsize(a);
		if (!stack_is_sorted(a))
			sorting(&a, &b, size);
	}
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
