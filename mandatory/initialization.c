/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:41 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/22 15:18:50 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(int total, int *numbers)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < total)
	{
		if (i == 0)
			stack_a = stack_new(numbers[i]);
		else
			stack_add_bottom(&stack_a, stack_new(numbers[i]));
		i++;
	}
	return (stack_a);
}

static void	init_indices(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	int		i;
	t_stack	*current;
	t_stack	*min_node;
	int		min_val;

	i = 0;
	init_indices(stack_a);
	while (i < stack_size)
	{
		current = stack_a;
		min_node = NULL;
		min_val = INT_MAX;
		while (current)
		{
			if (current->index == -1 && current->value <= min_val)
			{
				min_val = current->value;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->index = i++;
	}
}
