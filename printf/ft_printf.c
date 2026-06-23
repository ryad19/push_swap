/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:11:49 by achafai           #+#    #+#             */
/*   Updated: 2026/05/20 16:50:21 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cnvrs_hundeler(char spc, va_list *args)
{
	if (spc == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (spc == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (spc == 'p')
		return (ft_putptr(va_arg(*args, unsigned long long)));
	else if (spc == 'd' || spc == 'i')
		return (ft_putnbr(va_arg(*args, int), 10, 'd'));
	else if (spc == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int), 10, 'u'));
	else if (spc == 'x' || spc == 'X')
		return (ft_putnbr(va_arg(*args, unsigned int), 16, spc));
	else if (spc == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		sum;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				sum += cnvrs_hundeler(str[i], &args);
		}
		else
			sum += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(args);
	return (sum);
}
