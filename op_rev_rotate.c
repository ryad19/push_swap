/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:54:30 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/20 18:43:38 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Generic logic to shift all elements down by 1 (last becomes first)*/

static void	reverse_rotate_generic(t_stack **stack)
{
	if (!stack || !*stack || ((*stack)->next == *stack))
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_stack **stack_a, t_bench *bench)
{
	reverse_rotate_generic(stack_a);
	write(1, "rra\n", 4);
	if (bench && bench->enabled)
	{
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_stack **stack_b, t_bench *bench)
{
	reverse_rotate_generic(stack_b);
	write(1, "rrb\n", 4);
	if (bench && bench->enabled)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	reverse_rotate_generic(stack_a);
	reverse_rotate_generic(stack_b);
	write(1, "rrr\n", 4);
	if (bench && bench->enabled)
	{
		bench->rrr++;
		bench->total++;
	}
}
