/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:45:05 by idhaimy           #+#    #+#             */
/*   Updated: 2024/01/09 16:32:45 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void print_error(char *str)
{
    ft_putstr_fd("Error\n", 2);
    write(2,str,ft_strlen(str));
    exit(0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    print_error("KYS");
    printf("Hello, World!\n");
}