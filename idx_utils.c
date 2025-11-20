/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 06:25:47 by asergina          #+#    #+#             */
/*   Updated: 2025/11/20 06:26:16 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int size);
static void	fill_array(int *array, t_stack *stack);
static void	update_indexes(t_stack *stack, int *array, int size);
static int	find_index(int *array, int size, int value);

void	assign_indexes(t_stack **a, t_stack **b)
{
	int			size;
	int			*array;

	if (!a || !*a)
		return ;
	size = lstsize(*a);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		exit_with_error(a, b);
	fill_array(array, *a);
	sort_array(array, size);
	update_indexes(*a, array, size);
	free(array);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	fill_array(int *array, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
}

static void	update_indexes(t_stack *stack, int *array, int size)
{
	while (stack)
	{
		stack->index = find_index(array, size, stack->value);
		stack = stack->next;
	}
}

static int	find_index(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (0);
}
