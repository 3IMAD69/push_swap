/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:03:35 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/15 14:09:04 by idhaimy          ###   ########.fr       */
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

void	pa(t_stack **lst_a, t_stack **lst_b)
{
	if (!lst_b)
		return ;
	push_any(lst_a, lst_b);
	printf("pa\n");
}

void	pb(t_stack **lst_a, t_stack **lst_b)
{
	if (!lst_a)
		return ;
	push_any(lst_b, lst_a);
	printf("pb\n");
}
