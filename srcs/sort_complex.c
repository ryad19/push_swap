/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 08:07:18 by achafai           #+#    #+#             */
/*   Updated: 2026/07/01 15:40:47 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack **stack)
{
	int		max_bit;
	int		max_index;
	t_stack	*temp;

	if (!stack || !*stack)
		return (0);
	max_index = (*stack)->index;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	max_bit = 0;
	while ((max_index >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	int		i;
	int		j;
	int		size;
	int		bits;

	if (!a || !b || !*a)
		return ;
	bits = get_max_bits(a);
	size = stack_size(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(b, a, bench);
			j++;
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}
