/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 06:32:19 by asergina          #+#    #+#             */
/*   Updated: 2025/11/20 06:32:22 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_node(t_stack **a, t_stack **b, int number);
static void		is_repeat(t_stack **a, t_stack **b, int number);

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

int	the_smallest(t_stack **a, t_stack **b)
{
	int		smallest;
	t_stack	*stack_a;

	stack_a = *a;
	if (!stack_a)
		exit_with_error(a, b);
	smallest = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (smallest > stack_a->value)
			smallest = stack_a->value;
		stack_a = stack_a->next;
	}
	return (smallest);
}
