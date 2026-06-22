/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:21:06 by achafai           #+#    #+#             */
/*   Updated: 2026/06/22 08:16:12 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	pairs;
	t_stack	*end;
	t_stack	*temp;

	if (!a || (a->next == a))
		return (0.0f);
	end = a->prev;
	mistakes = 0;
	pairs = 0;
	while (a != end)
	{
		temp = a->next;
		while (temp != end->next)
		{
			pairs += 1;
			if (a->value > temp->value)
				mistakes += 1;
			temp = temp->next;
		}
		a = a->next;
	}
	return (mistakes / pairs);
}

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

int	strict_atoi(char *str, t_stack **a, char **arr)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!*str)
		exit_error(a, NULL, arr);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			exit_error(a, NULL, arr);
		str++;
	}
	return ((int)(num * sign));
}
