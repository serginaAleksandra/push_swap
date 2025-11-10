/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:16 by asergina          #+#    #+#             */
/*   Updated: 2025/11/09 20:45:31 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	swap_b(t_list **b)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	ss(t_list **a, t_list **b)
{
	swap_a(a);
	swap_b(b);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*first_b;

	if (!b || !*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	ft_lstadd_front(a, first_b);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = first_a->next;
	ft_lstadd_front(b, first_a);
}
