/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:10:41 by didara            #+#    #+#             */
/*   Updated: 2026/01/22 15:19:03 by soahrich         ###   ########.fr       */
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

int	get_number(char *str, int *dst)
{
	long	n;

	if (!is_num(str))
		return (0);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	*dst = (int)n;
	return (1);
}

int	parse_arg(char *arg, int *numbers, int *k)
{
	char	**args;
	int		j;

	args = ft_split(arg, ' ');
	if (!args)
		return (0);
	j = 0;
	while (args[j])
	{
		if (!get_number(args[j], &numbers[*k]))
			return (free_split(args), 0);
		(*k)++;
		j++;
	}
	free_split(args);
	return (1);
}

int	*store_numbers(int ac, char **av, int total)
{
	int	*numbers;
	int	i;
	int	k;

	numbers = malloc(sizeof(int) * total);
	if (!numbers)
		return (NULL);
	i = 1;
	k = 0;
	while (i < ac)
	{
		if (!parse_arg(av[i], numbers, &k))
			return (free(numbers), NULL);
		i++;
	}
	return (numbers);
}
