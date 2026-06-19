/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:52:09 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/19 12:02:21 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack **a, t_stack **b, char **arr)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	if (arr)
		free_split(arr);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
        return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	(*stack)->prev->next = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
