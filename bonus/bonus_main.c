/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:14:17 by didara            #+#    #+#             */
/*   Updated: 2026/01/26 10:24:22 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

static int	execute_instruction(char *instr, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(instr, "sa"))
		do_sa(a);
	else if (!ft_strcmp(instr, "sb"))
		do_sb(b);
	else if (!ft_strcmp(instr, "ss"))
		return (do_sa(a), do_sb(b), 1);
	else if (!ft_strcmp(instr, "pa"))
		do_pa(a, b);
	else if (!ft_strcmp(instr, "pb"))
		do_pb(a, b);
	else if (!ft_strcmp(instr, "ra"))
		do_ra(a);
	else if (!ft_strcmp(instr, "rb"))
		do_rb(b);
	else if (!ft_strcmp(instr, "rr"))
		return (do_ra(a), do_rb(b), 1);
	else if (!ft_strcmp(instr, "rra"))
		do_rra(a);
	else if (!ft_strcmp(instr, "rrb"))
		do_rrb(b);
	else if (!ft_strcmp(instr, "rrr"))
		return (do_rra(a), do_rrb(b), 1);
	else
		return (0);
	return (1);
}

static int	parse_and_init(int ac, char **av, t_stack **stack_a)
{
	int		total;
	int		*numbers;

	total = count_numbers(ac, av);
	if (total <= 0)
	{
		ft_error();
		return (1);
	}
	numbers = store_numbers(ac, av, total);
	if (!numbers)
		return (ft_error(), 1);
	if (has_duplicates(numbers, total))
		return (free(numbers), ft_error(), 1);
	*stack_a = fill_stack_values(total, numbers);
	if (!(*stack_a))
		return (free(numbers), ft_error(), 1);
	free(numbers);
	return (0);
}

static int	process_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		len;

	line = get_next_line(0);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (!execute_instruction(line, stack_a, stack_b))
		{
			free(line);
			free_stack(stack_a);
			free_stack(stack_b);
			ft_error();
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

static void	print_result(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (parse_and_init(ac, av, &stack_a))
		return (1);
	if (process_instructions(&stack_a, &stack_b))
		return (1);
	print_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
