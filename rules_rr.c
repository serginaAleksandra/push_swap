/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:16 by asergina          #+#    #+#             */
/*   Updated: 2025/11/10 20:18:51 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*new_first;
	t_list	*old_first;

	if (!a || !*a || !(*a)->next)
		return ;
	old_first = *a;
	new_first = (*a)->next;
	old_first->next = NULL;
	ft_lstadd_back(&new_first, old_first);
	*a = new_first;
}

void	rotate_b(t_list **b)
{
	t_list	*new_first;
	t_list	*old_first;

	if (!b || !*b || !(*b)->next)
		return ;
	old_first = *b;
	new_first = (*b)->next;
	old_first->next = NULL;
	ft_lstadd_back(&new_first, old_first);
	*b = new_first;
}

void	rr(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
}
