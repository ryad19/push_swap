/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:04:30 by achafai           #+#    #+#             */
/*   Updated: 2026/05/13 03:54:05 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*s;

	p = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*p++ = *s++;
	return ((void *)dest);
}
