#include "push_swap.h"

void	ft_lstprint(t_list *lst)
{

	while (lst != NULL)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	//t_list	*b;
	int		*content;

	a = NULL;
	//b = NULL;
	if (argc > 1)
	{
		i = 1;
		content = malloc(sizeof(*content));
		if (!content)
			return (1);
		*content = atoi_long(argv[i]);
		a = ft_lstnew((void *)content);
		while (argv[++i])
		{
			content = malloc(sizeof(*content));
			if (!content)
				return (1);
			*content = atoi_long(argv[i]);
			ft_lstadd_back(&a, ft_lstnew((void *)content));
		}
		ft_lstprint(a);
	}
	else

	return (0);
}
