/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarrbene <sarrbene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:23:22 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/09 11:47:40 by sarrbene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Generic logic to swap the top tpw elements of a stack*/

static void	swap_generic(t_stack **stack)
{
	t_stack		*first;
	t_stack		*second;

	if (!stack || !*stack ||!(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap_generic(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap_generic(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_generic(stack_a);
	swap_generic(stack_b);
	write(1, "ss\n", 3);
}
