/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:24:51 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/17 11:42:35 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	print_checker_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_for_double(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

void	init_commands(char **commands)
{
	commands[0] = "sa";
	commands[1] = "sb";
	commands[2] = "ss";
	commands[3] = "pa";
	commands[4] = "pb";
	commands[5] = "ra";
	commands[6] = "rb";
	commands[7] = "rr";
	commands[8] = "rra";
	commands[9] = "rrb";
	commands[10] = "rrr";
	commands[11] = NULL;
}
