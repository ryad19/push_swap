/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:52:09 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/07 17:09:42 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
