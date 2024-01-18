/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:03:35 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/18 13:28:21 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	push_any(t_stack **lst1, t_stack **lst2)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = (*lst2);
	next = tmp->next;
	(*lst2) = next;
	add_front(lst1, tmp);
}

void	pa(t_stack **lst_a, t_stack **lst_b, int is_print)
{
	if (!lst_b || list_size(*lst_b) < 1)
		return ;
	push_any(lst_a, lst_b);
	if (is_print)
		ft_printf("pa\n");
}

void	pb(t_stack **lst_a, t_stack **lst_b, int is_print)
{
	if (!lst_a || list_size(*lst_a) < 1)
		return ;
	push_any(lst_b, lst_a);
	if (is_print)
		ft_printf("pb\n");
}

void	print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	write(2, str, ft_strlen(str));
	exit(1);
}
