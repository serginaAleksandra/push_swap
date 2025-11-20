/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 06:34:23 by asergina          #+#    #+#             */
/*   Updated: 2025/11/20 06:35:52 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack);

static void	loop_in_loop(t_stack **a, t_stack **b, int size, int *bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*a)->index >> *bit) & 1)
			rotate_a(a);
		else
			push_b(a, b);
		i++;
	}
	while (*b)
		push_a(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bit;
	int	max_bits;

	if (!a || !*a)
		return ;
	size = lstsize(*a);
	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		loop_in_loop(a, b, size, &bit);
		if (stack_is_sorted(*a))
			return ;
		bit++;
	}
}

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits + 1);
}
