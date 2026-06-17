/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:54:09 by achafai           #+#    #+#             */
/*   Updated: 2026/06/17 17:00:28 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stknew(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = node;
	node->prev = node;
	return (node);
}

void	delnode(t_stack **node)
{
	t_stack	*temp;

	temp = *node;
	if (temp->next == temp)
		*node = NULL;
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		*node = temp->next;
	}
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
}
void	free_stack(t_stack **stack)
{
	t_stack	*current_n;
	t_stack	*next_n;

	if (!stack || !*stack)
		return ;
	current_n = *stack;
	current_n->prev->next = NULL;
	while (current_n)
	{
		next_n = current_n->next;
		free(current_n);
		current_n = next_n;
	}
	*stack = NULL;
}