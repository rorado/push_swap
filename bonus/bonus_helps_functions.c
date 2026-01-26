/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helps_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:12:41 by didara            #+#    #+#             */
/*   Updated: 2026/01/26 09:45:44 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	count_numbers(int ac, char **av)
{
	int		i;
	int		count;
	int		j;
	char	**args;

	i = 1;
	count = 0;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			return (-1);
		j = 0;
		while (args[j])
		{
			count++;
			j++;
		}
		free_split(args);
		i++;
	}
	return (count);
}
