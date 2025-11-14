/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:42:26 by aleksandra        #+#    #+#             */
/*   Updated: 2025/11/14 17:13:29 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	the_smallest(t_list	**a, t_list **b);

void	sort_two(t_list **a)
{
	int	first;
	int	second;

	if (!a || !*a)
        return ; // or exit_with_error();
	first = *(int *)(*a)->content;
	second = *(int *)((*a)->next->content);
	if (first > second)
		swap_a(a);
	return ;
}

void	sort_three(t_list **a, t_list **b)
{
	int	smallest;

	if (!a || !*a)
        return ; // or exit_with_error();
	smallest = the_smallest(a, b);
	while (*(int *)(*a)->content != smallest)
		rotate_a(a);
	push_b(a, b);
	sort_two(a);
	push_a(a, b);
}

void	sort_four(t_list **a, t_list **b)
{
	int	smallest;

	if (!a || !*a)
        return ; // or exit_with_error();
	smallest = the_smallest(a, b);
	while (*(int *)(*a)->content != smallest)
		rotate_a(a);
	push_b(a, b);
	sort_three(a, b);
	push_a(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	smallest;

	if (!a || !*a)
        return ; // or exit_with_error();
	smallest = the_smallest(a, b);
	while (*(int *)(*a)->content != smallest)
		rotate_a(a);
	push_b(a, b);
	sort_four(a, b);
	push_a(a, b);
}

static int	the_smallest(t_list **a, t_list **b)
{
	int	smallest;
	t_list	*stack_a;

	stack_a = *a;
	if (!stack_a)
		exit_with_error(a, b);
	smallest = *(int *)stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (smallest > *(int *)stack_a->content)
			smallest = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
	return (smallest);
}
