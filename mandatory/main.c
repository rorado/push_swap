/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:24:00 by didara            #+#    #+#             */
/*   Updated: 2026/01/26 20:17:02 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
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

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

static int	has_duplicates(int *nums, int size)
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

int	main(int ac, char **av)
{
	int		total;
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	total = count_numbers(ac, av);
	if (total <= 0)
		return (ft_error(), 1);
	numbers = store_numbers(ac, av, total);
	if (!numbers)
		return (ft_error(), 1);
	if (has_duplicates(numbers, total))
		return (free(numbers), ft_error(), 1);
	stack_b = NULL;
	stack_a = fill_stack_values(total, numbers);
	if (!stack_a)
		return (free(numbers), ft_error(), 1);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	return (free_stack(&stack_a), free_stack(&stack_b), free(numbers), 0);
}
