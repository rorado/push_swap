/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:00:00 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/10 00:00:00 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_numbers(int ac, char **av)
{
	int		i;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			return (-1);
		while (args[count])
			count++;
		free_split(args);
		i++;
	}
	return (count);
}

int	*store_numbers(int ac, char **av, int total)
{
	int		*numbers;
	char	**args;
	long	n;
	int		i;
	int		j;
	int		k;

	numbers = malloc(sizeof(int) * total);
	if (!numbers)
		return (NULL);
	i = 1;
	k = 0;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			return (free(numbers), NULL);
		j = 0;
		while (args[j])
		{
			if (!is_num(args[j]))
				return (free(numbers), free_split(args), NULL);
			n = ft_atol(args[j]);
			if (n < INT_MIN || n > INT_MAX)
				return (free(numbers), free_split(args), NULL);
			numbers[k++] = n;
			j++;
		}
		free_split(args);
		i++;
	}
	if (!set_index(numbers, total))
    {
        free(numbers);
        return (NULL);
    }
	return (numbers);
}
