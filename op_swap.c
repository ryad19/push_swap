/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:23:22 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/29 17:38:53 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Generic logic to swap the top tpw elements of a stack*/

static void	swap_generic(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || (*stack == (*stack)->next))
		return ;
	if ((*stack)->next->next == *stack)
	{
		*stack = (*stack)->next;
		return ;
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->prev->next = *stack;
	(*stack)->prev = temp->prev;
	temp->next = (*stack)->next;
	temp->next->prev = temp;
	(*stack)->next = temp;
	temp->prev = *stack;
}

void	sa(t_stack **stack_a, t_bench *bench)
{
	swap_generic(stack_a);
	write(1, "sa\n", 3);
	if (bench && bench->enabled)
	{
		bench->sa++;
		bench->total++;
	}
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	swap_generic(stack_b);
	write(1, "sb\n", 3);
	if (bench && bench->enabled)
	{
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	swap_generic(stack_a);
	swap_generic(stack_b);
	write(1, "ss\n", 3);
	if (bench && bench->enabled)
	{
		bench->ss++;
		bench->total++;
	}
}
