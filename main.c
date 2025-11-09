/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:43 by asergina          #+#    #+#             */
/*   Updated: 2025/11/09 20:46:05 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		param_processing(&a, argv);
		swap_a(&a);
		push_b(&a, &b);
		ft_printf("stack a\n");
		lstprint(a);
		ft_printf("stack b\n");
		lstprint(b);
	}
	return (0);
}
