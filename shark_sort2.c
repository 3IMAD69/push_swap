/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shark_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:39:46 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/19 11:04:58 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	go_back_to_a(t_stack **lst_a, t_stack **lst_b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*max;

	i = 0;
	tmp = *lst_b;
	while (tmp)
	{
		max = get_node_max(lst_b);
		if (max->index > list_size(*lst_b) / 2)
		{
			while ((*lst_b)->value != max->value)
				rrb(lst_b, 1);
			pa(lst_a, lst_b, 1);
		}
		else
		{
			while ((*lst_b)->value != max->value)
				rb(lst_b, 1);
			pa(lst_a, lst_b, 1);
		}
		i++;
		initiate_index(lst_b);
		tmp = *lst_b;
	}
}

void	increment_chunk_size(t_chunk *chunk, int size)
{
	if (chunk->end < size - 1)
		chunk->end++;
	if (chunk->start < chunk->end)
		chunk->start++;
}

void	main_shark_algo(t_chunk *chunk, t_stack **lst_a, t_stack **lst_b)
{
	int	size;

	size = list_size(*lst_a);
	while (*lst_a)
	{
		if ((*lst_a)->value <= chunk->sorted_arr[chunk->start])
		{
			pb(lst_a, lst_b, 1);
			rb(lst_b, 1);
			increment_chunk_size(chunk, size);
		}
		else if ((*lst_a)->value > chunk->sorted_arr[chunk->start]
			&& (*lst_a)->value <= chunk->sorted_arr[chunk->end])
		{
			pb(lst_a, lst_b, 1);
			if (list_size((*lst_b)) > 1 && (*lst_b)->value < (*lst_b)->next->value)
				sb(lst_b, 1);
			increment_chunk_size(chunk, size);
		}
		else
			ra(lst_a, 1);
	}
}

void	shark_sort(t_stack **lst_a, t_stack **lst_b)
{
	t_chunk	chunk;
	int		i;

	i = 0;
	fill_and_sort_arr(&chunk, lst_a);
	main_shark_algo(&chunk, lst_a, lst_b);
	initiate_index(lst_b);
	go_back_to_a(lst_a, lst_b);
	free(chunk.sorted_arr);
}
