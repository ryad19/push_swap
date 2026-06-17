/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:58:10 by achafai           #+#    #+#             */
/*   Updated: 2026/06/17 16:47:09 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generic_push(t_stack **src, t_stack **dest)
{
	t_stack *node;

	if (!src || !dest)
		return ;
	if (!*dest)
	{
		node = new_node((*src)->value);
		*dest = node;
		return ;
	}
	(*src)->next = *dest;
	(*src)->prev = (*dest)->prev;
	(*dest)->prev->next = (*src);
	(*dest) = (*src);
}