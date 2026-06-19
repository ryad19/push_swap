/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:25:32 by achafai           #+#    #+#             */
/*   Updated: 2026/06/19 15:49:25 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_stack *end;

    if (!stack || stack == stack->next)
        return (1);
    end = stack->prev;
    while (stack != end)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*end;

	if (!stack)
		return (0);
	end = stack->prev;
	size = 0;
	while (stack != end)
	{
		size++;
		stack = stack->next;
	}
	return (size);
	//return (stack->prev->index +1);
}

