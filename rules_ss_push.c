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

void	swap_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	swap_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*first_b;

	if (!b || !*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	lstadd_front(a, first_b);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = first_a->next;
	lstadd_front(b, first_a);
}
