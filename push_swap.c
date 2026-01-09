/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 07:50:24 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/09 16:47:34 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

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

int	has_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int **set_index(int *numbers)
{
	int		*numbers_i;
	int		i;

	i = 0;
	while (numbers[i])
	{
		
	}
	
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
	set_index(numbers);
	return (numbers);
}

int	main(int ac, char **av)
{
	int	total;
	int	*numbers;

	if (ac < 2)
		return (0);
	total = count_numbers(ac, av);
	if (total <= 0)
		return (ft_error());
	numbers = store_numbers(ac, av, total);
	if (!numbers)
		return (ft_error());
	if (has_duplicates(numbers, total))
		return (free(numbers), ft_error());

	/* TODO:
	 * - initialize stack A
	 * - apply push_swap algorithm
	 */

	free(numbers);
	return (0);
}
