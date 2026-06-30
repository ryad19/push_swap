/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:03:00 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/29 17:43:08 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper function to find the minimum index currently present in the stack.
int	get_min_index(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	min = stack->index;
	temp = stack->next;
	while (temp != stack)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}
// Helper Function to calculate the position of smallest element,
// rotate the stackto bring it to the top, and then push it  to Stack B.

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	t_stack	*tmp;
	int		pos;
	int		min_idx;
	int		size;

	pos = 0;
	tmp = *stack_a;
	size = stack_size(*stack_a);
	min_idx = get_min_index(*stack_a);
	while (tmp->index != min_idx)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack_a)->index != min_idx)
			ra(stack_a, bench);
	}
	else
	{
		while ((*stack_a)->index != min_idx)
			rra(stack_a, bench);
	}
	pb(stack_b, stack_a, bench);
}

// Function to sort 3 elements based on checking and comparing the top, middle,
// and bottom indices in the stack.

void	sort_three(t_stack **stack_a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	if (stack_size(*stack_a) != 3)
		return ;
	top = (*stack_a)->index;
	mid = (*stack_a)->next->index;
	bot = (*stack_a)->prev->index;
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

// Main Function for simple sortimg adapted only for 
//the first case (sizes from 0 to 2 indeces)

void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
	{
		sa(stack_a, bench);
		return ;
	}
	if (size == 3)
	{
		sort_three(stack_a, bench);
		return ;
	}
	else if (size == 4 || size == 5)
	{
		while (stack_size(*stack_a) > 3)
			push_min_to_b(stack_a, stack_b, bench);
		sort_three(stack_a, bench);
		while (*stack_b)
			pa(stack_a, stack_b, bench);
	}
}
