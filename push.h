/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:44:04 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/17 11:27:07 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "./includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				is_after_middle;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				n;
	int				start;
	int				end;
	int				*sorted_arr;
}					t_chunk;

typedef struct s_bonus
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			**str;
	char			*commands[12];
	char			*buffer;
}					t_bonus;

long long			ft_new_atoi(const char *str);
void				print_error(char *str);
int					free_tab(char **tab);
void				check_for_error(char **str);
t_stack				*create_new(int value, int index);
t_stack				*list_last(t_stack *lst);
void				add_back(t_stack **lst, t_stack *new);
void				add_front(t_stack **lst, t_stack *new);
int					list_size(t_stack *lst);
int					free_list(t_stack **lst);
void				print_stack(t_stack *lst);
char				**allocate_str(char **argv, int argc);
int					is_list_sorted(t_stack *lst);
int					get_max(t_stack *lst);
int					get_min(t_stack *lst);
void				sort_three(t_stack **lst_a);
void				sort_five(t_stack **lst_a, t_stack **lst_b);
void				sort_five_helper(t_stack **lst_a, t_stack **lst_b);
void				sort_four(t_stack **lst_a, t_stack **lst_b);
void				sort_four_helper(t_stack **lst_a, t_stack **lst_b);

void				sa(t_stack **lst, int is_print);
void				sb(t_stack **lst, int is_print);
void				ss(t_stack **lst_a, t_stack **lst_b, int is_print);

void				pa(t_stack **lst_a, t_stack **lst_b, int is_print);
void				pb(t_stack **lst_a, t_stack **lst_b, int is_print);

void				ra(t_stack **lst_a, int is_print);
void				rb(t_stack **lst_b, int is_print);
void				rr(t_stack **lst_b, t_stack **lst_a, int print);

void				rra(t_stack **lst_a, int is_print);
void				rrb(t_stack **lst_b, int is_print);
void				rrr(t_stack **lst_a, t_stack **lst_b, int is_print);

void				main_algo(t_stack **lst_a, t_stack **lst_b);
void				shark_sort(t_stack **lst_a, t_stack **lst_b);
int					get_max(t_stack *lst);
void				initiate_index(t_stack **lst_b);
void				shark_sort(t_stack **lst_a, t_stack **lst_b);
void				go_back_to_a(t_stack **lst_a, t_stack **lst_b);
t_stack				*get_node_max(t_stack **lst_b);
void				fill_and_sort_arr(t_chunk *chunk, t_stack **lst_a);
int					get_range(int size);

void				print_checker_error(void);
int					check_for_double(t_stack *lst);
void				init_commands(char **commands);

#endif