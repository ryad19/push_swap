/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:11:32 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/07 20:14:18 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

/* stack*/

t_stack				*new_node(int value);
void				add_back(t_stack **stack, t_stack *node);
void				free_stack(t_stack **stack);
int					stack_size(t_stack *stack);
/* utils*/

void				handle_error(t_stack **a, t_stack **b);
int					ft_isdigit(int c);
int					ft_is_num(char *str);
int					strict_atoi(char *str, t_stack **a);
void				parse_args(char **argv, int argc, t_stack **stack);

#endif