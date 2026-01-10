/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 07:07:36 by soahrich          #+#    #+#             */
/*   Updated: 2026/01/10 00:00:00 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* Stack structure */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* ft_split.c */
char	**ft_split(const char *s, char c);

/* ft_helpers.c */
int		ft_isdigit(int c);
void	ft_putstr(char *str);
int		ft_error(void);

/* ft_atoi.c */
long	ft_atol(char *str);

/* utils.c */
void	free_split(char **split);
int		has_duplicates(int *nums, int size);
int		set_index(int *numbers, int size);

/* parsing.c */
int		is_num(char *str);
int		count_numbers(int ac, char **av);
int		*store_numbers(int ac, char **av, int total);

/* stack.c */
t_stack	*new_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*init_stack(int *numbers, int size);

/* operations_swap.c */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

/* operations_push.c */
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

/* operations_rotate.c */
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

/* operations_rev_rotate.c */
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* sort_small.c */
int		is_sorted(t_stack *stack);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four_five(t_stack **a, t_stack **b);

/* sort_big.c */
void	radix_sort(t_stack **a, t_stack **b, int size);

/* sort.c */
void	push_swap(t_stack **a, t_stack **b);

#endif
