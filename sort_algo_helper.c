/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:15 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/17 11:44:36 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_four_helper(t_stack **lst_a, t_stack **lst_b)
{
	if (is_list_sorted(*lst_a))
		return ;
	pb(lst_a, lst_b, 1);
	initiate_index(lst_a);
	sort_three(lst_a);
	pa(lst_a, lst_b, 1);
}

void	sort_four(t_stack **lst_a, t_stack **lst_b)
{
	int		min;
	t_stack	*tmp;

	min = get_min(*lst_a);
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->value == min)
		{
			if (tmp->index > 1)
			{
				if (tmp->index == 2)
					rra(lst_a, 1);
				rra(lst_a, 1);
			}
			else if (tmp->index != 0)
				sa(lst_a, 1);
		}
		tmp = tmp->next;
	}
	sort_four_helper(lst_a, lst_b);
}

void	sort_five_helper(t_stack **lst_a, t_stack **lst_b)
{
	if (is_list_sorted(*lst_a))
		return ;
	pb(lst_a, lst_b, 1);
	initiate_index(lst_a);
	sort_four(lst_a, lst_b);
	pa(lst_a, lst_b, 1);
}

void	sort_five(t_stack **lst_a, t_stack **lst_b)
{
	int		min;
	t_stack	*tmp;

	min = get_min(*lst_a);
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->value == min)
		{
			if (tmp->index > 2)
			{
				if (tmp->index == 3)
					rra(lst_a, 1);
				rra(lst_a, 1);
			}
			else if (tmp->index != 0)
			{
				if (tmp->index == 2)
					ra(lst_a, 1);
				ra(lst_a, 1);
			}
		}
		tmp = tmp->next;
	}
	sort_five_helper(lst_a, lst_b);
}
