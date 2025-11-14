#include "push_swap.h"

static void	is_digit(const char *nptr, t_list **a, t_list **b);
static void	is_repeat(t_list **a, t_list **b);

static long	atoi_long(const char *nptr, t_list	**a, t_list **b)
{
	int		sign;
	long	result;
	int		i;

	is_digit(nptr, a, b);
	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		exit_with_error(a, b);
	return (result);
}

void	param_processing(t_list **a, t_list **b, char **param)
{
	int	*content;
	int	i;

	i = 1;
	if (ft_strlen(param[i]) > 11)
		exit_with_error(a, b);
	content = malloc(sizeof(*content));
	if (!content)
		exit_with_error(a, b);
	*content = atoi_long(param[i], a, b);
	*a = ft_lstnew((void *)content);
	if (!(*a))
		exit_with_error(a, b);
	while (param[++i])
	{
		if (ft_strlen(param[i]) > 11)
			exit_with_error(a, b);
		content = malloc(sizeof(*content));
		if (!content)
			exit_with_error(a, b);
		*content = atoi_long(param[i], a, b);
		ft_lstadd_back(a, ft_lstnew((void *)content)); // if error inside lstnew
	}
	is_repeat(a, b);
}

static void	is_digit(const char *nptr, t_list **a, t_list **b)
{
	int		i;

	i = 0;
	while (nptr[i])
	{
		if ((nptr[i] < '0' && nptr[i] != '+' && nptr[i] != '-') || nptr[i] > '9' ||
				((nptr[i] == '-' || nptr[i] == '+') && (i != 0 || !nptr[i + 1])))
			exit_with_error(a, b);
		i++;
	}
}

static void	is_repeat(t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*a_next;

	stack_a = (*a);
	while (stack_a)
	{
		a_next = stack_a->next;
		while (a_next)
		{
			if (*(int *)stack_a->content == *(int *)a_next->content)
				exit_with_error(a, b);
			a_next = a_next->next;
		}
		stack_a = stack_a->next;
	}
}
