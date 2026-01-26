/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahrich <soahrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:25:53 by didara            #+#    #+#             */
/*   Updated: 2026/01/26 20:16:52 by soahrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

int		count_numbers(int ac, char **av);
int		*store_numbers(int ac, char **av, int total);
int		is_sorted(t_stack *stack);

t_stack	*fill_stack_values(int total, int *numbers);

void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	**ft_split(char *s, char c);
void	*free_buff(char *buffer, char *stash);
void	*ft_memcpy(void *dest, const void *src, size_t n);

int		ft_isdigit(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *s);

long	ft_atol(const char *str);

int		has_duplicates(int *nums, int size);
int		is_empty(t_stack *stack);

void	free_split(char **split);
void	free_stack(t_stack **stack);
void	ft_error(void);

t_stack	*stack_new(int value);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *new);

#endif
