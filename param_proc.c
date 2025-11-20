#include "push_swap.h"

static void	is_digit(const char *nptr, t_stack **a, t_stack **b);
static void	process_argument(char *arg, t_stack **a, t_stack **b);
static char	**split_argument(char *arg, t_stack **a, t_stack **b);
static void	push_tokens(char **split, t_stack **a, t_stack **b);
static void	free_split(char **split);
static void	split_error(char **split, t_stack **a, t_stack **b);

static long	atoi_long(const char *nptr, t_stack	**a, t_stack **b)
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
		if ((nptr[i] < '0' && nptr[i] != '+' && nptr[i] != '-') || nptr[i] > '9' ||
				((nptr[i] == '-' || nptr[i] == '+') && (i != 0 || !nptr[i + 1])))
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

static void	process_argument(char *arg, t_stack **a, t_stack **b)
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
	int	idx;
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


