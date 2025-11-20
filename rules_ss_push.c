/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ss_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 06:30:34 by asergina          #+#    #+#             */
/*   Updated: 2025/11/20 06:36:36 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	if (swap_nodes(a))
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	if (swap_nodes(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	performed;

	performed = 0;
	performed += swap_nodes(a);
	performed += swap_nodes(b);
	if (performed)
		write(1, "ss\n", 3);
}

void	push_a(t_stack **a, t_stack **b)
{
	if (push_node_to(b, a))
		write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (push_node_to(a, b))
		write(1, "pb\n", 3);
}
