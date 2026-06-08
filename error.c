/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:52:09 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/08 18:59:23 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(int value, t_stack *stk)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = stk;
	while (i < stack_size(stk))
	{
		if (value == node->value)
			return (1);
		node = node->next;
	}
	return (0);
}

void	handle_error(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;
	t_stack	*end;

	i = a;
	mistakes = 0;
	total_pairs = 0;
	end = a->prev;
	while (i != end)
	{
		j = i->next;
		while (j != end->next)
		{
			total_pairs += 1;
			if (i->value > j->value)
				mistakes += 1;
			j = j->next;
		}
		i = i->next; 
	}
	return (mistakes / total_pairs);
}
