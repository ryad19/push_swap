/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 08:49:31 by achafai           #+#    #+#             */
/*   Updated: 2026/05/19 17:09:17 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int b, char f)
{
	int		len;
	char	*symb;

	len = 0;
	if (f == 'X')
		symb = "0123456789ABCDEF";
	else
		symb = "0123456789abcdef";
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= b)
		len += ft_putnbr(n / b, b, f);
	len += ft_putchar(symb[n % b]);
	return (len);
}
