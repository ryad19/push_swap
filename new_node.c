/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:33:58 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/06 17:12:12 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack		*node;

	node = malloc(sizeof (t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
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
