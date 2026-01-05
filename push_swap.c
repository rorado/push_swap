/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 07:50:24 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/04 19:14:29 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_integer(char *str)
{
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        return 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
int check_args(char **args)
{
    int     i;
    long    n;

    i = 0;
    if (!args || !args[0])
        return (0);
    while (args[i])
    {
        if (!is_integer(args[i]))
            return (0);
        n = ft_atol(args[i]);
        if (n < INT_MIN || n > INT_MAX)
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char *av[])
{
    int     i;
    char    **args;

    if (ac < 2)
        return (0);
    i = 1;
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        if (!args)
            return (ft_error());

        if (!check_args(args))
        {
            free_split(args);
            return (ft_error());
        }
        free_split(args);
        i++;
    }
    return (0);
}
