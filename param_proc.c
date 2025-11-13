#include "push_swap.h"

long	atoi_long(const char *nptr)
{
	int		sign;
	long	result;
	int		i;

	if (ft_strlen(nptr) > 11)
		exit_with_error();
	i = -1;
	while (nptr[++i])
	{
		if ((nptr[i] < '0' && nptr[i] != '+' && nptr[i] != '-') || nptr[i] > '9' ||
				((nptr[i] == '-' || nptr[i] == '+') && (i != 0 || !nptr[i + 1])))
			exit_with_error();
	}
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
		exit_with_error();
	return (result);
}

void	param_processing(t_list **a, char **param)
{
	int	*content;
	int	i;

	i = 1;
	content = malloc(sizeof(*content));
	if (!content)
		exit_with_error();
	*content = atoi_long(param[i]);
	*a = ft_lstnew((void *)content);
	if (!(*a))
		exit_with_error();
	while (param[++i])
	{
		content = malloc(sizeof(*content));
		if (!content)
			exit_with_error();
		*content = atoi_long(param[i]);
		ft_lstadd_back(a, ft_lstnew((void *)content)); // if error inside lstnew
	}
}

void	is_repeats(t_list **a)
{
	
}