/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shark_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:39:02 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/19 18:13:19 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	imad_sort(t_chunk *chunk, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (chunk->sorted_arr[i] < chunk->sorted_arr[j])
			{
				tmp = chunk->sorted_arr[i];
				chunk->sorted_arr[i] = chunk->sorted_arr[j];
				chunk->sorted_arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_range(int size)
{
	if (size >= 6 && size <= 16)
		return (3);
	else if (size <= 100)
		return (15);
	else if (size <= 500)
		return (35);
	return (45);
}

void	fill_and_sort_arr(t_chunk *chunk, t_stack **lst_a)
{
	t_stack	*tmp;
	int		i;
	int		size;

	size = list_size(*lst_a);
	i = 0;
	chunk->n = get_range(size);
	chunk->start = 0;
	chunk->end = chunk->n - 1;
	chunk->sorted_arr = (int *)malloc(size * sizeof(int));
	if (!chunk->sorted_arr)
		return ;
	tmp = *lst_a;
	while (tmp)
	{
		chunk->sorted_arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	imad_sort(chunk, size);
}

void	initiate_index(t_stack **lst_b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *lst_b;
	while (i < list_size(*lst_b))
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

t_stack	*get_node_max(t_stack **lst_b)
{
	t_stack	*tmp;
	t_stack	*max_node;

	tmp = *lst_b;
	max_node = *lst_b;
	while (tmp)
	{
		if (tmp->value > max_node->value)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}
