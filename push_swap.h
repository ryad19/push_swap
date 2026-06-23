/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:11:32 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/23 07:38:52 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "print/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

typedef struct s_bench
{
	int				enabled;
	int				total;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

/* parsing.c */
t_strategy			parse_strategy(char *arg);
void				parse_numbers(t_stack **a, int argc, char **argv,
						int start_indx);
int					has_duplicates(t_stack *stack);
void				print_float_fd(float num, int fd);
void				print_bench(t_bench *bench, t_strategy strategy,
						double disorder);

/* utils_memory.c */
void				exit_error(t_stack **a, t_stack **b, char **arr);
void				free_stack(t_stack **stack);
void				free_split(char **arr);

/* utils_math.c */
int					ft_is_num(char *str);
int					strict_atoi(char *str, t_stack **a, char **arr);
float				compute_disorder(t_stack *a);

/* stack_utils.c */
t_stack				*new_node(int value);
void				add_back(t_stack **stack, t_stack *node);
int					stack_size(t_stack *stack);
int					is_sorted(t_stack *stack);
void				assign_indx(t_stack *stack);

/* op_push.c */
void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);

/* op_swap.c */
void				sa(t_stack **a, t_bench *bench);
void				sb(t_stack **a, t_bench *bench);
void				ss(t_stack **a, t_stack **b, t_bench *bench);

/* op_rotate.c */
void				ra(t_stack **a, t_bench *bench);
void				rb(t_stack **a, t_bench *bench);
void				rr(t_stack **a, t_stack **b, t_bench *bench);

/* op_rev_rotate.c */
void				rra(t_stack **a, t_bench *bench);
void				rrb(t_stack **a, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);

/* sort_simple.c */
int					get_min_index(t_stack *stack);
void				sort_three(t_stack **a, t_bench *bench);
void				push_min_to_b(t_stack **a, t_stack **b, t_bench *bench);
void				sort_simple(t_stack **a, t_stack **b, t_bench *bench);

/* sort_medium.c */

/* sort_complex.c */

#endif