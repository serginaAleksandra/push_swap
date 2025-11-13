// ...existing code...
#include "push_swap.h"

static int	the_smallest(t_list *lst);
static int	list_len(t_list *lst);
static int	index_of_smallest(t_list *lst);
static void	bring_index_to_top(t_list **a, int idx);

/* changed: direct minimal 3-element sort */
void	sort_three(t_list **a, t_list **b)
{
    int	first;
    int	second;
    int	third;

    (void)b;
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return ;
    first = *(int *)(*a)->content;
    second = *(int *)(*a)->next->content;
    third = *(int *)(*a)->next->next->content;
    if (first < second && second < third)
        return ;
    if (first > second && second < third && first < third) /* 2 1 3 */
        swap_a(a);
    else if (first > second && second > third) /* 3 2 1 */
    {
        swap_a(a);
        reverse_rotate_a(a);
    }
    else if (first > second && second < third && first > third) /* 3 1 2 */
        rotate_a(a);
    else if (first < second && second > third && first < third) /* 1 3 2 */
    {
        swap_a(a);
        rotate_a(a);
    }
    else if (first < second && second > third && first > third) /* 2 3 1 */
        reverse_rotate_a(a);
}

/* bring smallest with minimal rotations, then push */
void	sort_four(t_list **a, t_list **b)
{
    int	idx;

    if (!a || !*a)
        return ;
    idx = index_of_smallest(*a);
    bring_index_to_top(a, idx);
    push_b(a, b);
    sort_three(a, b);
    push_a(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
    int	idx;

    if (!a || !*a)
        return ;
    /* push two smallest: repeat twice */
    idx = index_of_smallest(*a);
    bring_index_to_top(a, idx);
    push_b(a, b);
    idx = index_of_smallest(*a);
    bring_index_to_top(a, idx);
    push_b(a, b);
    sort_three(a, b);
    /* push back the two smallest */
    push_a(a, b);
    push_a(a, b);
}

/* helpers */

static int	list_len(t_list *lst)
{
    int	len = 0;
    while (lst)
    {
        len++;
        lst = lst->next;
    }
    return (len);
}

static int	index_of_smallest(t_list *lst)
{
    int	smallest;
    int	idx = 0;
    int	best = 0;

    if (!lst)
        exit_with_error();
    smallest = *(int *)lst->content;
    while (lst)
    {
        if (*(int *)lst->content < smallest)
        {
            smallest = *(int *)lst->content;
            best = idx;
        }
        lst = lst->next;
        idx++;
    }
    return (best);
}

/* rotate up or down the minimal number of times to bring idx to 0 */
static void	bring_index_to_top(t_list **a, int idx)
{
    int	len;

    len = list_len(*a);
    if (idx <= len / 2)
    {
        while (idx-- > 0)
            rotate_a(a);
    }
    else
    {
        while (idx++ < len)
            reverse_rotate_a(a);
    }
}

static int	the_smallest(t_list *lst)
{
    int	smallest;

    if (!lst)
        exit_with_error();
    smallest = *(int *)lst->content;
    lst = lst->next;
    while (lst)
    {
        if (*(int *)lst->content < smallest)
            smallest = *(int *)lst->content;
        lst = lst->next;
    }
    return (smallest);
}
// ...existing code...