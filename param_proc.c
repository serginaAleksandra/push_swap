#include "push_swap.h"

static void	is_digit(const char *nptr, t_stack **a, t_stack **b);

long	atoi_long(const char *nptr, t_stack	**a, t_stack **b)
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
	while (nptr[i] == '0')
		i++;
	if (ft_strlen(&nptr[i]) > 10)
		exit_with_error(a, b);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		exit_with_error(a, b);
	return (result);
}

static void	is_digit(const char *nptr, t_stack **a, t_stack **b)
{
	int		i;

	i = 0;
	while (nptr[i])
	{
		if ((nptr[i] < '0' && nptr[i] != '+' && nptr[i] != '-')
			|| nptr[i] > '9'
			|| ((nptr[i] == '-' || nptr[i] == '+')
				&& (i != 0 || !nptr[i + 1])))
			exit_with_error(a, b);
		i++;
	}
}

void	param_processing(t_stack **a, t_stack **b, char **param, int argc)
{
	argc--;
	while (argc > 0)
	{
		process_argument(param[argc], a, b);
		argc--;
	}
	assign_indexes(a, b);
}
