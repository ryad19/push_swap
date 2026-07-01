/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:32:43 by sarrbene          #+#    #+#             */
/*   Updated: 2026/07/01 13:12:20 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*Generic logic to shift all elements up by 1 (first becomes last)*/

static void	rotate_generic(t_stack **stack)
{
	if (!stack || !*stack || ((*stack)->next == *stack))
		return ;
	*stack = (*stack)->next;
}

void	ra(t_stack **stack_a, t_bench *bench)
{
	rotate_generic(stack_a);
	write(1, "ra\n", 3);
	if (bench && bench->enabled)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	rotate_generic(stack_b);
	write(1, "rb\n", 3);
	if (bench && bench->enabled)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rotate_generic(stack_a);
	rotate_generic(stack_b);
	write(1, "rr\n", 3);
	if (bench && bench->enabled)
	{
		bench->rr++;
		bench->total++;
	}
}
