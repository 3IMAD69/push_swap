#include "push.h"

int get_max(t_stack *lst)
{
    int max;

    max = lst->value;
    while (lst->next)
    {
        if (max < lst->next->value)
            max = lst->next->value;
        lst = lst->next;
    }
    return (max);
}

int get_min(t_stack *lst)
{
    int min;

    min = lst->value;
    while (lst->next)
    {
        if (min > lst->next->value)
            min = lst->next->value;
        lst = lst->next;
    }
    return (min);
}

void sort_three(t_stack **lst_a)
{
    int max;
    int min;
    t_stack *last;
    
    min = get_min(*lst_a);
    max = get_max(*lst_a);
    last = list_last(*lst_a);
    if (last->value == max)
        sa(lst_a,1);
    else if (last->value == min)
    {
        if ((*lst_a)->value == max)
            sa(lst_a,1);
        rra(lst_a,1);
    }
    else
    {
        if ((*lst_a)->value != max)
            sa(lst_a,1);
        ra(lst_a,1);
    }
}

void sort_four_helper(t_stack **lst_a,t_stack **lst_b)
{
    pb(lst_a,lst_b);
    sort_three(lst_a);
    pa(lst_a,lst_b);
}

void sort_four(t_stack **lst_a,t_stack **lst_b)
{
    int min;
    t_stack *tmp;

    min = get_min(*lst_a);
    tmp = *lst_a;
    while (tmp)
    {
        if (tmp->value == min)
        {
            if (tmp->index > 1)
            {
                if (tmp->index == 2)
                    rra(lst_a,1);
                rra(lst_a,1);
            }
            else if (tmp->index != 0)
                sa(lst_a,1);
        }
        tmp = tmp->next;
    }
    sort_four_helper(lst_a,lst_b);
}

void sort_five_helper(t_stack **lst_a,t_stack **lst_b)
{
    pb(lst_a,lst_b);
    initiate_index(lst_a);
    sort_four(lst_a,lst_b);
    pa(lst_a,lst_b);
}

void sort_five(t_stack **lst_a,t_stack **lst_b)
{
    int min;
    t_stack *tmp;

    min = get_min(*lst_a);
    tmp = *lst_a;
    while (tmp)
    {
        if (tmp->value == min)
        {
            if (tmp->index > 2)
            {
                if (tmp->index == 3)
                    rra(lst_a,1);
                rra(lst_a,1);
            }
            else if (tmp->index != 0)
            {
                if (tmp->index == 2)
                    ra(lst_a,1);
                ra(lst_a,1);
            }
        }
        tmp = tmp->next;
    }
    sort_five_helper(lst_a,lst_b);
    //(void)lst_b;
}

void main_algo(t_stack **lst_a, t_stack **lst_b)
{
    (void)lst_b;
    if (list_size(*lst_a) == 2)
        sa(lst_a,1);
    else if (list_size(*lst_a) == 3)
        sort_three(lst_a);
    else if (list_size(*lst_a) == 4)
        sort_four(lst_a,lst_b);
    else if (list_size(*lst_a) == 5)
        sort_five(lst_a,lst_b);
    else
        shark_sort(lst_a,lst_b);
    
}
