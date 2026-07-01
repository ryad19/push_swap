/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:04:29 by sarrbene          #+#    #+#             */
/*   Updated: 2026/07/01 13:12:15 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*Generic logic to push the top element from one stack to another*/

static void	push_generic(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_move;

	if (!src || !*src || !dest)
		return ;
	node_to_move = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = node_to_move->prev;
		node_to_move->prev->next = *src;
		node_to_move->next = node_to_move;
		node_to_move->prev = node_to_move;
	}
	if (*dest)
	{
		node_to_move->next = *dest;
		node_to_move->prev = (*dest)->prev;
		(*dest)->prev->next = node_to_move;
		(*dest)->prev = node_to_move;
	}
	*dest = node_to_move;
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push_generic(stack_a, stack_b);
	write(1, "pa\n", 3);
	if (bench && bench->enabled)
	{
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a, t_bench *bench)
{
	push_generic(stack_b, stack_a);
	write(1, "pb\n", 3);
	if (bench && bench->enabled)
	{
		bench->pb++;
		bench->total++;
	}
}
