/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:38:46 by asergina          #+#    #+#             */
/*   Updated: 2025/11/19 18:49:36 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft_printf/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;


void	exit_with_error(t_stack	**a, t_stack **b);
void	print_stack(t_stack *lst);
void	free_stack(t_stack **stack);
void	push_node(t_stack **a, t_stack **b, int value);
void	param_processing(t_stack **a, t_stack **b, char **param, int argc);
t_stack	*lstlast(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	lstremove_last(t_stack *lst);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		lstsize(t_stack *lst);

#endif