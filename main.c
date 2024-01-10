/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:45:05 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/10 12:20:29 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_for_double(t_stack *lst)
{
	t_stack *tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		lst= lst->next;
	}
	return (0);
}

void fill_stack(char **str,t_stack **stack_a, int size)
{
	t_stack *new;
	int i;
	int middle;

	i = 0;
	while (str[i])
	{
		middle = 0;
		if (i >= (size / 2))
			middle = 1;
		new = create_new(ft_new_atoi(str[i]), i, middle);
		add_back(stack_a, new);
		if(check_for_double(*stack_a) == 1 && free_tab(str) && free_list(stack_a))
			print_error("double detected");
		i++;
	}
	free_tab(str);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **str;
	int size;

	size = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		print_error("arg not valid");
	if (argc == 2)
		str = ft_split(argv[1],' ');
	else
		str = allocate_str(argv, argc);
	check_for_error(str);
	while (str[size] != NULL)
		size++;
	printf("size of stack %d\n",size);
	fill_stack(str, &stack_a, size);
	print_stack(stack_a);
	//system("leaks push_swap");
}

