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

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		param_processing(&a, &b, argv, argc);
		ft_printf("stack a\n");
		print_stack(a);
		if (!a)
			exit_with_error(&a, &b);
		if (argc == 3)
			sort_two(&a);
		if (argc == 4)
			sort_three(&a);
		if (argc == 5)
			sort_four(&a, &b);
		if (argc == 6)
			sort_five(&a, &b);
		ft_printf("stack a\n");
		print_stack(a);
		ft_printf("stack b\n");
		print_stack(b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
