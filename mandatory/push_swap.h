/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:47:42 by didara            #+#    #+#             */
/*   Updated: 2026/01/26 20:17:23 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int value);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *new);
int		get_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

int		count_numbers(int ac, char **av);
int		*store_numbers(int ac, char **av, int total);

t_stack	*fill_stack_values(int total, int *numbers);
void	assign_index(t_stack *stack_a, int stack_size);
int		is_sorted(t_stack *stack);

void	tiny_sort(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		get_lowest_index_position(t_stack **stack);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);

long	ft_atol(const char *str);
void	ft_putstr(char *str);
int		nb_abs(int nb);
int		ft_error(void);
char	**ft_split(char *s, char c);
void	free_split(char **split);
int		ft_strlen(char *s);
int		ft_isdigit(char c);
int		is_sign(char c);

#endif
