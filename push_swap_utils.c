/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:54:09 by achafai           #+#    #+#             */
/*   Updated: 2026/06/17 17:03:09 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
