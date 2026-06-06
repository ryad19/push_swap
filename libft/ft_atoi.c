/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:53:59 by achafai           #+#    #+#             */
/*   Updated: 2026/05/09 10:25:30 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
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
		str++;
	}
	return (num * sign);
}
