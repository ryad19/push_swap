/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 03:13:47 by achafai           #+#    #+#             */
/*   Updated: 2026/06/07 19:52:31 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	strict_atoi(char *str, t_stack **a)
{
	long	i;
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = (num * 10) + (*str - 48);
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			handle_error(a, NULL);
		str++;
	}
	return ((int)(num * sign));
}

void	parse_args(char **argv, int argc)
{
	int		i;
	int		content;
	t_stack	*stack;

	if (argc < 2)
		handle_error(NULL, NULL);
	i = 1;
	while (i < argc)
	{
		content = strict_atoi(argv[i], &stack);
		add_back(&stack, new_node(content));
		i++;
	}
}
