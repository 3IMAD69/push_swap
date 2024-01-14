
#include "push.h"

void imad_sort(t_chunk *chunk,int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size)
    {
        j = 0 ;
        while (j < i)
        {
            if (chunk->sorted_arr[i] < chunk->sorted_arr[j])
            {
                tmp = chunk->sorted_arr[i];
                chunk->sorted_arr[i] = chunk->sorted_arr[j];
                chunk->sorted_arr[j] = tmp;
            }
            j++;
        }
        i++;
    } 
}

int get_range(int size)
{
    
    if (size >= 6 && size <= 16)
        return (3);
    else if (size <= 100)
        return (13);
    else if (size <= 500)
        return (35);
    return (0);
}
void fill_and_sort_arr(t_chunk *chunk,t_stack **lst_a)
{
    t_stack *tmp;
    int i;

    i = 0;
    chunk->sorted_arr  = (int *)malloc(list_size(*lst_a) * sizeof(int));
    if (!chunk->sorted_arr)
        return ;
    tmp = *lst_a;
    while (tmp)
    {
        chunk->sorted_arr[i++] = tmp->value;
        tmp = tmp->next;
    }   
    imad_sort(chunk,list_size(*lst_a));
}

void initiate_index(t_stack **lst_b)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = *lst_b;
    while (i < list_size(*lst_b))
    {
        tmp->index = i;
        tmp = tmp->next;
        i++;
    } 
}

t_stack *get_node_max(t_stack **lst_b)
{
    t_stack    *tmp;
    t_stack *max_node;

    tmp = *lst_b;
    max_node = *lst_b;
    while (tmp)
    {
        if (tmp->value > max_node->value)
            max_node = tmp;
        tmp = tmp->next;
    }
    return (max_node);
}

void go_back_to_a(t_stack **lst_a,t_stack **lst_b)
{
    int i;
    t_stack *tmp;
    t_stack *max;

    i = 0;
    tmp = *lst_b;
    while (tmp)
    {
        max = get_node_max(lst_b);
        if (max->index > list_size(*lst_b) / 2)
        {
            while ((*lst_b)->value != max->value)
                rrb(lst_b, 1);
            pa(lst_a,lst_b);
        }
        else
        {
            while ((*lst_b)->value != max->value)
                rb(lst_b, 1);
            pa(lst_a,lst_b);
        }
        i++; 
        initiate_index(lst_b);
        tmp = *lst_b;
    }
}

void shark_sort(t_stack **lst_a,t_stack **lst_b)
{
    t_chunk chunk;
    int i;
    t_stack *tmp;
    int size;

    size = list_size(*lst_a);
    i = 0;
    fill_and_sort_arr(&chunk,lst_a);
    chunk.n = get_range(size);
    chunk.start = 0 ;
    chunk.end = chunk.n - 1 ;
    tmp = *lst_a;
    while (tmp)
    {
        if (tmp->value <= chunk.sorted_arr[chunk.start])
        {
            pb(lst_a,lst_b);
            rb(lst_b, 1);
            if (chunk.end < size - 1)
                chunk.end++;
            if (chunk.start < chunk.end)
                chunk.start++;        
        }
        else if (tmp->value > chunk.sorted_arr[chunk.start] && tmp->value <= chunk.sorted_arr[chunk.end])
        {
             pb(lst_a,lst_b);
            if (list_size((*lst_b)) && (*lst_b)->next &&(*lst_b)->value < (*lst_b)->next->value)
                sb(lst_b, 1);
            if (chunk.end < size - 1)
                chunk.end++;
            if (chunk.start < chunk.end)
                chunk.start++;
        }
        else 
            ra(lst_a, 1);
        tmp = *lst_a;   
    }
    initiate_index(lst_b);
    go_back_to_a(lst_a,lst_b);
}




