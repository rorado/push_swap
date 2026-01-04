/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 07:50:24 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/04 19:10:56 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main (int ac, char *av[])
{
    
}