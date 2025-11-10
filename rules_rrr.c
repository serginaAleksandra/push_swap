/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2 copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:16 by asergina          #+#    #+#             */
/*   Updated: 2025/11/10 20:17:33 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **a)
{
	t_list	*old_last;

	if (!a || !*a || !(*a)->next)
		return ;
	old_last = ft_lstlast(*a);
	lstremove_last(*a);
	ft_lstadd_front(a, old_last);
}

void	reverse_rotate_b(t_list **b)
{
	t_list	*old_last;

	if (!b || !*b || !(*b)->next)
		return ;
	old_last = ft_lstlast(*b);
	lstremove_last(*b);
	ft_lstadd_front(b, old_last);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}

void	lstremove_last(t_list *lst)
{
	t_list	*last;

	last = ft_lstlast(lst);
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
}
