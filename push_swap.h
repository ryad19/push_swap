/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:11:32 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/07 17:10:08 by achafai          ###   ########.fr       */
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

void	handle_error(t_stack **a, t_stack **b);

#endif