/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarrbene <sarrbene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:39:46 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/06 17:58:02 by sarrbene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Srict atoi that flags non-digits and detects integer overflow*/

long long	ft_atoi_strict(const char *str, int *error)
{
	long long	result;
	int			i;
	int			sign;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (*error = 1, 0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (*error = 1, 0);
		result = result * 10 + (str[i] - '0');
		if ((sign * result) > INT_MAX || (sign * result) < INT_MAX)
			return (*error = 1, 0);
		i++;
	}
	return (sign * result);
}
/*Scans the existing stack nodes to check for duplicate numbers*/

int	has_duplicates(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}


