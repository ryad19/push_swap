/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:56:50 by achafai           #+#    #+#             */
/*   Updated: 2026/06/19 12:02:48 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = node;
	node->prev = node;
	return (node);
}

void	add_back(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	(*stack)->prev->next = node;
	node->prev = (*stack)->prev;
	node->next = *stack;
	(*stack)->prev = node;
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
