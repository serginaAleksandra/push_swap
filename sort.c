/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:42:26 by aleksandra        #+#    #+#             */
/*   Updated: 2025/11/20 05:47:15 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stack **b)
{
	int	first;
	int	second;

	if (!a || !*a || !(*a)->next)
		exit_with_error(a, b);
	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		swap_a(a);
}

static void	first_third(int first, int second, int third, t_stack **a)
{
	if (first > third)
	{
		rotate_a(a);
		if (second > third)
			swap_a(a);
	}
	else
		swap_a(a);
	return ;
}

void	sort_three(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		exit_with_error(a, b);
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		return ;
	if (first < second)
	{
		reverse_rotate_a(a);
		if (first < third)
			swap_a(a);
		return ;
	}
	else
	{
		first_third(first, second, third, a);
		return ;
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	smallest;

	if (!a || !*a || lstsize(*a) < 4)
		exit_with_error(a, b);
	smallest = the_smallest(a, b);
	while ((*a)->value != smallest)
		rotate_a(a);
	push_b(a, b);
	sort_three(a, b);
	push_a(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	smallest;
	int	two;

	if (!a || !*a || lstsize(*a) < 5)
		exit_with_error(a, b);
	two = 0;
	while (two < 2)
	{
		smallest = the_smallest(a, b);
		while ((*a)->value != smallest)
			rotate_a(a);
		push_b(a, b);
		two++;
	}
	sort_three(a, b);
	push_a(a, b);
	push_a(a, b);
}
