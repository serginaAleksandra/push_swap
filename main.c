/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:43 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 20:46:16 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	stack_is_sorted(t_stack *a)
// {
// 	if (!a)
// 		return (1);
// 	while (a && a->next)
// 	{
// 		if (a->value > a->next->value)
// 			return (0);
// 		a = a->next;
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		param_processing(&a, &b, argv, argc);
		if (!a)
			exit_with_error(&a, &b);
		size = lstsize(a);
		if (!stack_is_sorted(a))
		{
			if (size == 2)
				sort_two(&a);
			else if (size == 3)
				sort_three(&a);
			else if (size == 4)
				sort_four(&a, &b);
			else if (size == 5)
				sort_five(&a, &b);
			else
				radix_sort(&a, &b);
		}
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
