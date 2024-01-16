/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:16:51 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/16 16:31:29 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

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

void init_commands(char **commands)
{
    commands[0] = "sa";
    commands[1] = "sb";
    commands[2] = "ss";//
    commands[3] = "pa";//
    commands[4] = "pb";//
    commands[5] = "ra";
    commands[6] = "rb";
    commands[7] = "rr";//
    commands[8] = "rra";
    commands[9] = "rrb";
    commands[10] = "rrr";//
    commands[11] = NULL;
}

void	fill_stack(char **str, t_stack **stack_a)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (str[i])
	{
		new = create_new(ft_new_atoi(str[i]), i);
		add_back(stack_a, new);
		if (check_for_double(*stack_a) == 1 && free_tab(str)
			&& free_list(stack_a))
			print_error("Invalid Argument");
		i++;
	}
	free_tab(str);
}

int check_if_valide_command(char *str,char **commands)
{
    int i;

    i = 0;
    while(commands[i])
    {
        if (ft_strncmp(str,commands[i],ft_strlen(str) + 1) == 0)
            return (i);
        i++;
    }
    return (-1);
}
void do_the_command_on_stack(t_stack **stack_a,t_stack **stack_b,int instruction_index)
{
	// int fd = open("/dev/null",O_RDWR);
	// dup2(fd,STDOUT_FILENO);
	if (instruction_index == 0)
		sa(stack_a,0);
	else if (instruction_index == 1)
		sb(stack_b,0);
	else if (instruction_index == 2)
		ss(stack_a,stack_b);
	else if (instruction_index == 3)
		pa(stack_a,stack_b);
	else if (instruction_index == 4)
		pb(stack_a,stack_b);
	else if (instruction_index == 5)
		ra(stack_a,0);
	else if (instruction_index == 6)
		rb(stack_b,0);
	else if (instruction_index == 7)
		rr(stack_b,stack_a);
	else if (instruction_index == 8)
		rra(stack_a,0);
	else if (instruction_index == 9)
		rrb(stack_a,0);
	else if (instruction_index == 10)
		rrr(stack_a,stack_b);
	// close(fd);
}
void print_checker_error()
{
	ft_putstr_fd("Error\n",2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_bonus bonus;
	int instruction_index;

	bonus.stack_a = NULL;
	bonus.stack_b = NULL;
    init_commands(bonus.commands);
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		bonus.str = ft_split(argv[1], ' ');
	else
		bonus.str = allocate_str(argv, argc);
	check_for_error(bonus.str);
	fill_stack(bonus.str, &(bonus.stack_a));
    bonus.buffer = get_next_line(STDIN_FILENO);
    while (bonus.buffer)
    {
		bonus.buffer[ft_strlen(bonus.buffer) - 1] = '\0';
		instruction_index = check_if_valide_command(bonus.buffer,bonus.commands);
        if (instruction_index == -1)
        {
			free(bonus.buffer);
			free_list(&(bonus.stack_a));
			free_list(&(bonus.stack_b));
            print_checker_error();
	    }
		else
			do_the_command_on_stack(&(bonus.stack_a),&(bonus.stack_b),instruction_index);
        free(bonus.buffer);
        bonus.buffer = get_next_line(STDIN_FILENO);
    }
	free(bonus.buffer);
	if(is_list_sorted(bonus.stack_a) && list_size(bonus.stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	// if (is_list_sorted(stack_a) && free_list(&stack_a))
	// 	return (0);
	// // print_stack(stack_a);
	// main_algo(&stack_a, &stack_b);
	// free_list(&stack_a);
	//   print_stack(stack_b);
	// printf("************************after************************\n");
	// print_stack(stack_a);
	//system("leaks push_swap");
}
