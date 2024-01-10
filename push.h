/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:44:04 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/09 16:29:19 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "./includes/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int             value;
    int             index;
    int             is_after_middle;
    int             cost;
    struct s_stack  *next;
} t_stack;


long long	ft_new_atoi(const char *str);
void print_error(char *str);
int	free_tab(char **tab);
void check_for_error(char **str);
t_stack *create_new (int value, int index, int is_after_middle);
t_stack *list_last(t_stack *lst);
void add_back(t_stack **lst,t_stack *new);
void add_front(t_stack **lst,t_stack *new);
int list_size(t_stack *lst);
int free_list(t_stack **lst);
void print_stack(t_stack *lst);
char **allocate_str(char **argv,int argc);


#endif