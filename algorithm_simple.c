/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarrbene <sarrbene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:03:00 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/22 16:58:37 by sarrbene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Helper function to find the minimum index currently present in the stack.
static int	get_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack->next;
	}
	return (min);
}
// Helper Function to calculate the position of smallest element, 
// rotate the stackto bring it to the top, and then push it  to Stack B.

static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	t_stack	*tmp;
	int		pos;
	int		min_idx;

	pos = 0;
	tmp = *stack_a;
	min_idx = get_min_index(*stack_a);
	while (tmp && tmp->index != min_idx)
	{
		pos++;
		tmp = tmp->index;
	}
	if (pos <= bench->size_a / 2)
	{
		while ((*stack_a)->index != min_idx)
			ra(stack_a, bench);
	}
	else
	{
		while ((*stack_a)->index != min_idx)
			rra(stack_a, bench);
	}
	pb (stack_b, stack_a, bench);
}

// Function to sort 3 elements based on checking and comparing the top, middle, and bottom indices in the stack.

void	sort_three(t_stack **stack_, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->index;
	mid = (*stack_a)->next->index;
	bot = (*stack_a)->next->next->index;
	if (top > mid && mid > bot)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (top > bot && bot > mid)
		ra(stack_a, bench);
	else if (mid > top && top > bot)
		rra(stack_a, bench);
	else if (top > bot && mid > bot)
		sa(stack_a, bench);
	else if (bot > top && mid > bot)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
}

// Main Function for simple sortimg adapted only for the first case (sizes from 0 to 2 indeces)

void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	(void)stack_b;
	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	if (bench->size_a == 2)
	{
		sa(stack_a, bench);
		return ;
	}
	if (bench->size_a == 3)
	{
		sort_three(stack_a, bench);
		return ;
	}
}
