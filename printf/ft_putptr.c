/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 08:58:37 by achafai           #+#    #+#             */
/*   Updated: 2026/05/19 17:18:55 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_putnbr(unsigned long long n)
{
	int		len;
	char	*symb;

	len = 0;
	symb = "0123456789abcdef";
	if (n >= 16)
		len += ft_unsigned_putnbr(n / 16);
	len += ft_putchar(symb[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_unsigned_putnbr(ptr);
	return (len);
}
