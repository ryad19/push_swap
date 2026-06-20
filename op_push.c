/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarrbene <sarrbene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:04:29 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/09 13:27:10 by sarrbene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Generic logic to push the top element from one stack to another*/

static void	push_generic(t_stack **dest, t_stack **src)
{
	t_stack		*node_to_move;

	if (!src ||!*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_move;
	*dest = node_to_move;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_generic(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	push_generic(stack_b, stack_a);
	write(1, "pb\n", 3);
}
