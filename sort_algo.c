/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:14:42 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/15 14:44:05 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_max(t_stack *lst)
{
	int	max;

	max = lst->value;
	while (lst->next)
	{
		if (max < lst->next->value)
			max = lst->next->value;
		lst = lst->next;
	}
	return (max);
}

int	get_min(t_stack *lst)
{
	int	min;

	min = lst->value;
	while (lst->next)
	{
		if (min > lst->next->value)
			min = lst->next->value;
		lst = lst->next;
	}
	return (min);
}

void	sort_three(t_stack **lst_a)
{
	int		max;
	int		min;
	t_stack	*last;

	min = get_min(*lst_a);
	max = get_max(*lst_a);
	last = list_last(*lst_a);
	if (last->value == max)
		sa(lst_a, 1);
	else if (last->value == min)
	{
		if ((*lst_a)->value == max)
			sa(lst_a, 1);
		rra(lst_a, 1);
	}
	else
	{
		if ((*lst_a)->value != max)
			sa(lst_a, 1);
		ra(lst_a, 1);
	}
}

void	main_algo(t_stack **lst_a, t_stack **lst_b)
{
	if (list_size(*lst_a) == 2)
		sa(lst_a, 1);
	else if (list_size(*lst_a) == 3)
		sort_three(lst_a);
	else if (list_size(*lst_a) == 4)
		sort_four(lst_a, lst_b);
	else if (list_size(*lst_a) == 5)
		sort_five(lst_a, lst_b);
	else
		shark_sort(lst_a, lst_b);
}
