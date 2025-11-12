/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:38:46 by asergina          #+#    #+#             */
/*   Updated: 2025/11/12 20:20:45 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft_printf/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	exit_with_error();
long	atoi_long(const char *nptr);
void	lstprint(t_list *lst);
void	param_processing(t_list **a, char **param);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	ss(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rr(t_list **a, t_list **b);
void	lstremove_last(t_list *lst);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	rrr(t_list **a, t_list **b);
void	sort_three(t_list **a);

#endif