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

void	rotate_a(t_stack **a)
{
	t_stack	*new_first;
	t_stack	*old_first;

	if (!a || !*a || !(*a)->next)
		return ;
	old_first = *a;
	new_first = (*a)->next;
	old_first->next = NULL;
	lstadd_back(&new_first, old_first);
	*a = new_first;
}

void	rotate_b(t_stack **b)
{
	t_stack	*new_first;
	t_stack	*old_first;

	if (!b || !*b || !(*b)->next)
		return ;
	old_first = *b;
	new_first = (*b)->next;
	old_first->next = NULL;
	lstadd_back(&new_first, old_first);
	*b = new_first;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}
