/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarrbene <sarrbene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:54:30 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/09 14:01:27 by sarrbene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Generic logic to shift all elements down by 1 (last becomes first)*/

static void	reverse_rotate_generic(t_stack **stack)
{
	t_stack		*first;
	t_stack		*last;

	if (!stack || !*stack ||!(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_generic(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_generic(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_generic(stack_a);
	reverse_rotate_generic(stack_b);
	write(1, "rrr\n", 4);
}
