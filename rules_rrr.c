/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:16 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 17:23:13 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack **stack);

void	reverse_rotate_a(t_stack **a)
{
	if (reverse_rotate_stack(a))
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	if (reverse_rotate_stack(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	int	rotated;

	rotated = 0;
	rotated += reverse_rotate_stack(a);
	rotated += reverse_rotate_stack(b);
	if (rotated)
		write(1, "rrr\n", 4);
}

static int	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*old_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	old_last = lstlast(*stack);
	lstremove_last(*stack);
	lstadd_front(stack, old_last);
	return (1);
}

void	lstremove_last(t_stack *lst)
{
	t_stack	*last;

	last = lstlast(lst);
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
}
