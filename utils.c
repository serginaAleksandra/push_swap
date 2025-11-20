/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:35 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 17:26:43 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_repeat(t_stack **a, t_stack **b, int number);
static t_stack	*init_node(t_stack **a, t_stack **b, int number);
static void	sort_array(int *array, int size);
static int	find_index(int *array, int size, int value);
static void	fill_array(int *array, t_stack *stack);
static void	update_indexes(t_stack *stack, int *array, int size);

void	exit_with_error(t_stack	**a, t_stack **b)
{
	ft_printf("Error\n");
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}

void	print_stack(t_stack *stack)
{

	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	push_node(t_stack **a, t_stack **b, int number)
{
	t_stack	*new_node;

	is_repeat(a, b, number);
	new_node = init_node(a, b, number);
	if (!new_node)
		exit_with_error(a, b);
	new_node->next = *a;
	*a = new_node;
}

static t_stack	*init_node(t_stack **a, t_stack **b, int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (exit_with_error(a, b), NULL);
	new->next = NULL;
	new->value = number;
	new->index = 0;
	return (new);
}

static void	is_repeat(t_stack **a, t_stack **b, int number)
{
	t_stack	*stack_a;

	stack_a = (*a);
	while (stack_a)
	{
		if (stack_a->value == number)
			exit_with_error(a, b);
		stack_a = stack_a->next;
	}
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

void	assign_indexes(t_stack **a, t_stack **b)
{
	int			size;
	int			*array;

	if (!a || !*a)
		return ;
	size = lstsize(*a);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		exit_with_error(a, b);
	fill_array(array, *a);
	sort_array(array, size);
	update_indexes(*a, array, size);
	free(array);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (0);
}

static void	fill_array(int *array, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
}

static void	update_indexes(t_stack *stack, int *array, int size)
{
	while (stack)
	{
		stack->index = find_index(array, size, stack->value);
		stack = stack->next;
	}
}
