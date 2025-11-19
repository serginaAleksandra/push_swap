/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:43 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 18:45:47 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
