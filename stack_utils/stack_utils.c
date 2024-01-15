/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:06:49 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/15 17:04:33 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	swap_any(t_stack **lst)
{
	int	tmp;

	tmp = (*lst)->value;
	(*lst)->value = (*lst)->next->value;
	(*lst)->next->value = tmp;
}

void	sa(t_stack **lst, int is_print)
{
	if (!lst || list_size(*lst) < 2)
		return ;
	swap_any(lst);
	if (is_print)
		ft_printf("sa\n");
}

void	sb(t_stack **lst, int is_print)
{
	if (!lst || list_size(*lst) < 2)
		return ;
	swap_any(lst);
	if (is_print)
		ft_printf("sb\n");
}

void	ss(t_stack **lst_a, t_stack **lst_b)
{
	sa(lst_a, 0);
	sb(lst_b, 0);
	ft_printf("ss\n");
}
