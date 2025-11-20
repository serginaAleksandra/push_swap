/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:35 by asergina          #+#    #+#             */
/*   Updated: 2025/11/20 05:14:27 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_repeat(t_stack **a, t_stack **b, int number);
static t_stack	*init_node(t_stack **a, t_stack **b, int number);

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
