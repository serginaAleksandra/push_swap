/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ss_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:16 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 17:23:28 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_nodes(t_stack **stack);
static int	push_node_to(t_stack **from, t_stack **to);

void	swap_a(t_stack **a)
{
	if (swap_nodes(a))
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	if (swap_nodes(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	performed;

	performed = 0;
	performed += swap_nodes(a);
	performed += swap_nodes(b);
	if (performed)
		write(1, "ss\n", 3);
}

void	push_a(t_stack **a, t_stack **b)
{
	if (push_node_to(b, a))
		write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (push_node_to(a, b))
		write(1, "pb\n", 3);
}

static int	swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	return (1);
}

static int	push_node_to(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!from || !*from)
		return (0);
	first = *from;
	*from = first->next;
	lstadd_front(to, first);
	return (1);
}
