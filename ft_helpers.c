/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 00:36:50 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/06 01:03:40 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;

    while (*str)
        write(1, str++, 1);
}

int ft_error(void)
{
    write(2, "Error\n", 6);
    return (0);
}
