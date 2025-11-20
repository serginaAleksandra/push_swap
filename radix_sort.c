#include "push_swap.h"

static int	get_max_bits(t_stack *stack);

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bit;
	int	i;
	int	max_bits;

	if (!a || !*a)
		return ;
	size = lstsize(*a);
	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				rotate_a(a);
			else
				push_b(a, b);
			i++;
		}
		while (*b)
			push_a(a, b);
		if (stack_is_sorted(*a))
			return ;
		bit++;
	}
}

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits + 1);
}