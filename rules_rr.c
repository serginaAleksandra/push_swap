/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:16 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 17:22:46 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack **stack);

void	rotate_a(t_stack **a)
{
	if (rotate_stack(a))
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	if (rotate_stack(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	int	rotated;

	rotated = 0;
	rotated += rotate_stack(a);
	rotated += rotate_stack(b);
	if (rotated)
		write(1, "rr\n", 3);
}

static int	rotate_stack(t_stack **stack)
{
	t_stack	*new_first;
	t_stack	*old_first;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	old_first = *stack;
	new_first = (*stack)->next;
	old_first->next = NULL;
	lstadd_back(&new_first, old_first);
	*stack = new_first;
	return (1);
}
