/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:38:37 by didara            #+#    #+#             */
/*   Updated: 2026/01/26 10:01:26 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}
