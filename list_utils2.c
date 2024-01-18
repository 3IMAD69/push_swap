/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:43:04 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/18 15:17:17 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	free_list(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	return (1);
}

int	get_str_size(char **argv, int argc)
{
	int		i;
	int		count;
	char	**splited_arg;
	int		j;

	i = 1;
	j = 0;
	count = 0;
	while (i < argc)
	{
		if (ft_strnstr(argv[i], " ", ft_strlen(argv[i])))
		{
			splited_arg = ft_split(argv[i], ' ');
			while (splited_arg[j++])
				count++;
			free_tab(splited_arg);
			j = 0;
		}
		i++;
	}
	return (count);
}

void	put_splited_to_str(char **str, char *arg, int *j)
{
	char	**splitted;
	int		k;

	k = 0;
	splitted = ft_split(arg, ' ');
	while (splitted[k])
	{
		str[*j] = ft_strdup(splitted[k]);
		(*j)++;
		k++;
	}
	free(arg);
	free_tab(splitted);
}

int	check_if_non_space(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**allocate_str(char **argv, int argc)
{
	int		i;
	int		j;
	char	**str;
	char	*tmp;

	i = 1;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (argc + get_str_size(argv, argc)));
	while (i < argc)
	{
		tmp = ft_strdup(argv[i]);
		if (!tmp)
			return (NULL);
		if (ft_strnstr(tmp, " ", ft_strlen(tmp))
			&& check_if_non_space(tmp) == 1)
			put_splited_to_str(str, tmp, &j);
		else
			str[j++] = tmp;
		i++;
	}
	str[j] = NULL;
	return (str);
}
