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

void	reverse_rotate_a(t_stack **a)
{
	t_stack	*old_last;

	if (!a || !*a || !(*a)->next)
		return ;
	old_last = lstlast(*a);
	lstremove_last(*a);
	lstadd_front(a, old_last);
}

void	reverse_rotate_b(t_stack **b)
{
	t_stack	*old_last;

	if (!b || !*b || !(*b)->next)
		return ;
	old_last = lstlast(*b);
	lstremove_last(*b);
	lstadd_front(b, old_last);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}

void	lstremove_last(t_stack *lst)
{
	t_stack	*last;

	last = lstlast(lst);
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
}
