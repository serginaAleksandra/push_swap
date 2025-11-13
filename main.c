/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:43 by asergina          #+#    #+#             */
/*   Updated: 2025/11/13 20:24:38 by aleksandra       ###   ########.fr       */
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
		if (argc == 3)
			sort_two(&a);
		if (argc == 4)
			sort_three(&a, &b);
		if (argc == 5)
			sort_four(&a, &b);
		if (argc == 6)
			sort_five(&a, &b);
		ft_printf("stack a\n");
		lstprint(a);
		ft_printf("stack b\n");
		lstprint(b);
	}
	return (0);
}
