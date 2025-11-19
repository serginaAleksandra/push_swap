/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:19:25 by aleksandra        #+#    #+#             */
/*   Updated: 2025/11/19 18:29:35 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
}

int	lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}