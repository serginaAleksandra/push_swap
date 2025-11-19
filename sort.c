/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:42:26 by aleksandra        #+#    #+#             */
/*   Updated: 2025/11/19 18:30:16 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	the_smallest(t_stack **a, t_stack **b);

void	sort_two(t_stack **a)
{
	int	first;
	int	second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		swap_a(a);
}

// void	sort_three(t_stack **a, t_stack **b)
// {
// 	int	smallest;

// 	if (!a || !*a)
//         return ; // or exit_with_error();
// 	smallest = the_smallest(a, b);
// 	while ((*a)->value != smallest)
// 		rotate_a(a);
// 	push_b(a, b);
// 	sort_two(a);
// 	push_a(a, b);
// }

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
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
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	smallest;

	if (!a || !*a || lstsize(*a) < 4)
        return ; // or exit_with_error();
	smallest = the_smallest(a, b);
	while ((*a)->value != smallest)
		rotate_a(a);
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	smallest;
	int	two;

	if (!a || !*a || lstsize(*a) < 5)
        return ; // or exit_with_error();
	two = 0;
	while (two < 2)
	{
		smallest = the_smallest(a, b);
		while ((*a)->value != smallest)
			rotate_a(a);
		push_b(a, b);
		two++;
	}
	sort_three(a);
	push_a(a, b);
}

static int	the_smallest(t_stack **a, t_stack **b)
{
	int	smallest;
	t_stack *stack_a;

	stack_a = *a;
	if (!stack_a)
		exit_with_error(a, b);
	smallest = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (smallest > stack_a->value)
			smallest = stack_a->value;
		stack_a = stack_a->next;
	}
	return (smallest);
}
