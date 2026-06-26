/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:25:32 by achafai           #+#    #+#             */
/*   Updated: 2026/06/25 17:43:09 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
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

int	is_sorted(t_stack *stack)
{
	t_stack	*end;

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
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack->next;
	size = 1;
	while (stack != temp->next)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	assign_indx(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cmp;
	int		count;
	int		i;
	int		j;

	if (!stack)
		return ;
	current = stack;
	i = 0;
	while (i++ < stack_size(stack))
	{
		count = 0;
		cmp = stack;
		j = 0;
		while (j++ < stack_size(stack))
		{
			if (current->value < cmp->value)
				count++;
			cmp = cmp->next;
		}
		current->index = cmp->index;
		current = current->next;
	}
}
