
#include "push_swap.h"

int	swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	return (1);
}

int	push_node_to(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!from || !*from)
		return (0);
	first = *from;
	*from = first->next;
	lstadd_front(to, first);
	return (1);
}