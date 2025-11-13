/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:12:35 by asergina          #+#    #+#             */
/*   Updated: 2025/11/13 22:05:09 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error()
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	lstprint(t_list *lst)
{

	while (lst != NULL)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}
