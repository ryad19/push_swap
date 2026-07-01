/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:48:05 by achafai           #+#    #+#             */
/*   Updated: 2026/07/01 13:12:32 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	find_root(int n)
{
	int	i;

	i = 1;
	while (i < n / i)
		i++;
	return (i);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*temp;

	if (!stack)
		return (NULL);
	max = stack;
	temp = stack->next;
	while (temp != stack)
	{
		if (max->index < temp->index)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

void	phase_two(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*temp;
	t_stack	*max;
	int		distance;
	int		size;

	while (*b)
	{
		max = get_max(*b);
		size = stack_size(*b);
		temp = *b;
		distance = 0;
		while (temp != max)
		{
			distance++;
			temp = temp->next;
		}
		if (distance <= size / 2)
			while (*b != max)
				rb(b, bench);
		else
			while (*b != max)
				rrb(b, bench);
		pa(a, b, bench);
	}
}

void	phase_one(t_stack **a, t_stack **b, t_bench *bench, int chunk_size)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(b, a, bench);
			rb(b, bench);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk_size)
		{
			pb(b, a, bench);
			pushed++;
		}
		else
			ra(a, bench);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	chunck_size;

	size = stack_size(*a);
	chunck_size = find_root(size);
	phase_one(a, b, bench, chunck_size);
	phase_two(a, b, bench);
}
