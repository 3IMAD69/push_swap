
#include "push.h"

void swap_any(t_stack **lst)
{
    int tmp;

    tmp = (*lst)->value;
    (*lst)->value = (*lst)->next->value;
    (*lst)->next->value = tmp;
}

void sa(t_stack **lst, int is_print)
{
    if (!lst || list_size(*lst) < 2)
        return;
    swap_any(lst);
    if (is_print)
        printf("sa\n");
}

void sb(t_stack **lst, int is_print)
{
    if (!lst || list_size(*lst) < 2)
        return;
    swap_any(lst);
    if (is_print)
        printf("sb\n");
}

void ss(t_stack **lst_a,t_stack **lst_b)
{
    sa(lst_a, 0);
    sb(lst_b, 0);
    printf("ss\n");
}
void push_any(t_stack **lst1,t_stack **lst2)
{
    t_stack *tmp;
    t_stack *next;

    tmp = (*lst2);
    next = tmp->next;
    (*lst2) = next;
    add_front(lst1,tmp);
}

void pa(t_stack **lst_a,t_stack **lst_b)
{
    if (!lst_b)
        return ;
    push_any(lst_a,lst_b);
    printf("pa\n");
}

void pb(t_stack **lst_a,t_stack **lst_b)
{
    if (!lst_a)
        return ;
    push_any(lst_b,lst_a);
    printf("pb\n");
}

void    rotate_any(t_stack **lst)
{
    t_stack *head;
    t_stack *next;
    t_stack *tmp;
    
    head = *lst;
    next = head->next;
    tmp = list_last(*lst);
    *lst = next;
    tmp->next = head;
    head->next = NULL;
}

void ra(t_stack **lst_a, int is_print)
{
    if (!lst_a || list_size(*lst_a) < 2)
        return ;
    rotate_any(lst_a);
    if (is_print)
        printf("ra\n");
}

void rb(t_stack **lst_b, int is_print)
{
    if (!lst_b || list_size(*lst_b) < 2)
        return ;
    rotate_any(lst_b);
    if (is_print)
        printf("rb\n");
}

void rr(t_stack **lst_b,t_stack **lst_a)
{
    ra(lst_a, 0);
    rb(lst_b, 0);
    printf("rr\n");
}

void    rotate_revesre_any(t_stack **lst)
{
    t_stack *last;
    t_stack *before_last;
    t_stack *tmp;

    before_last = *lst;
    last = list_last(*lst);
    tmp = *lst;
    while (tmp->next->next)
    {
        tmp = tmp->next;
        before_last = tmp;
    }
    last->next = *lst;
    *lst = last;
    before_last->next = NULL;
}


void rra(t_stack **lst_a,int is_print)
{
    if (!lst_a || list_size(*lst_a) < 2)
        return ;
    rotate_revesre_any(lst_a);
    if (is_print)
        printf("rra\n");
}

void rrb(t_stack **lst_b,int is_print)
{
    if (!lst_b || list_size(*lst_b) < 2)
        return ;
    rotate_revesre_any(lst_b);
    if (is_print)
        printf("rrb\n");
}

void rrr(t_stack **lst_a,t_stack **lst_b)
{
    rra(lst_a, 0);
    rrb(lst_b, 0);
    printf("rrr\n");
}



