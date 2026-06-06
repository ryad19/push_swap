/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarrbene <sarrbene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:11:32 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/05 19:24:03 by sarrbene         ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* stack*/

t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
int		stack_size(t_stack *stack);
/* utils*/

void	print_error_and_exit(t_stack **a, t_stack **b, char **args, int is_split);
void	free_matrix(char **matrix);

/*Parsing*/

long long 	ft_atoi_strict(const char *str, int *error);
void	process_and_fill_stack(char **args, t_stack **stack, int is_split);

#endif
