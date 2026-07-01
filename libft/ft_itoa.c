/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:45:38 by achafai           #+#    #+#             */
/*   Updated: 2026/05/12 01:25:56 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	char	sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = size(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	sign = '+';
	if (n < 0)
	{
		sign = '-';
		n *= -1;
	}
	str[len--] = '\0';
	while (len >= 0 && (sign == '+' || len >= 1))
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == '-')
		str[0] = '-';
	return (str);
}
