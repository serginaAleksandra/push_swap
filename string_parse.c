/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:57:41 by aleksandra        #+#    #+#             */
/*   Updated: 2025/11/20 02:08:18 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_argument(char *arg, t_stack **a, t_stack **b);
static void	push_tokens(char **split, t_stack **a, t_stack **b);
static void	free_split(char **split);
static void	split_error(char **split, t_stack **a, t_stack **b);

void	process_argument(char *arg, t_stack **a, t_stack **b)
{
	char	**split;

	split = split_argument(arg, a, b);
	push_tokens(split, a, b);
	free_split(split);
}

static char	**split_argument(char *arg, t_stack **a, t_stack **b)
{
	char	**split;
	int		count;

	if (!arg || *arg == '\0')
		exit_with_error(a, b);
	split = ft_split(arg, ' ');
	if (!split)
		exit_with_error(a, b);
	count = 0;
	while (split[count])
		count++;
	if (count == 0)
		split_error(split, a, b);
	return (split);
}

static void	push_tokens(char **split, t_stack **a, t_stack **b)
{
	int		idx;
	long	number;

	idx = 0;
	while (split[idx])
		idx++;
	idx--;
	while (idx >= 0)
	{
		if (ft_strlen(split[idx]) == 0)
			split_error(split, a, b);
		number = atoi_long(split[idx], a, b);
		push_node(a, b, (int)number);
		idx--;
	}
}

static void	free_split(char **split)
{
	int	idx;

	if (!split)
		return ;
	idx = 0;
	while (split[idx])
	{
		free(split[idx]);
		idx++;
	}
	free(split);
}

static void	split_error(char **split, t_stack **a, t_stack **b)
{
	free_split(split);
	exit_with_error(a, b);
}


