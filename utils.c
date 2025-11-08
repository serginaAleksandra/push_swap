#include "push_swap.h"

void	exit_with_error()
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

long atoi_long(const char *nptr)
{
	int		sign;
	long	result;
	int		i;

	if (ft_strlen(nptr) > 11)
		exit_with_error();
	i = 0;
	while (nptr[i])
	{
		if ((nptr[i] < '0' && nptr[i] != '+' && nptr[i] != '-') || nptr[i] > '9')
			exit_with_error();
		i++;
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
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		exit_with_error();
	return (result);
}