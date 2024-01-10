
#include "push.h"

t_stack *create_new (int value, int index, int is_after_middle)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->index = index;
    new->is_after_middle = is_after_middle;
    new->cost = 0;
    new->next = NULL;
    return (new);
}

t_stack *list_last(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void add_back(t_stack **lst,t_stack *new)
{
    t_stack *tmp;

    if (!new)
        return ;
    tmp = list_last(*lst);
    if (!tmp)
        *lst = new;
    else
        tmp->next = new;
}

void add_front(t_stack **lst,t_stack *new)
{
    if (!new)
        return ;
    new->next = *lst;
    *lst = new;    
}

int list_size(t_stack *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }    
    return (i);
}


int free_list(t_stack **lst)
{
    t_stack *tmp;

    while(*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
    return (1);
}

void print_stack(t_stack *lst)
{
    if (!lst)
        printf("NULL to print stack");
    while(lst)
    {
        printf("Value => %d\n",lst->value);
        printf("index => %d\n",lst->index);
        printf("is_after_middle => %d\n",lst->is_after_middle);
        printf("cost => %d\n",lst->cost);
        lst = lst->next;
        printf("//////////////////\n\n");
    }
}

char **allocate_str(char **argv,int argc)
{
    int i;
    int j;
    char **str;
    char *tmp;
    
    i = 1;
    j = 0;
    str = (char **)malloc (sizeof(char *) * argc);
    while(i < argc)
    {
        tmp = ft_strdup(argv[i]);
        if (!tmp)
            return (NULL);
        str[j] = tmp;
        i++;
        j++;
    }
    str[j] = NULL;
    return (str);
}











