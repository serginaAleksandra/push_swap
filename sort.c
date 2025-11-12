#include "push_swap.h"

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)->content;
	second = *(int *)((*a)->next)->content;
	third = *(int *)((*a)->next->next)->content;
	if (first < second && second < third)
		return ;
	if (first < second)
	{
		reverse_rotate_a(a);
		if (first < third)
			swap_a(a);
		return ;
	}
	else
	{
		if (first > third)
		{
			rotate_a(a);
			if (second > third)
				swap_a(a);
		}
		else
			swap_a(a);
		return ;
	}
}
