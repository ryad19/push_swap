/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:40:52 by achafai           #+#    #+#             */
/*   Updated: 2026/05/06 19:11:45 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	d_size;

	i = 0;
	d_size = (size_t)ft_strlen(dest);
	len = d_size;
	if (size <= d_size)
		return (ft_strlen(src) + size);
	while (src[i] && d_size < (size - 1))
		dest[d_size++] = src[i++];
	dest[d_size] = '\0';
	return (len + ft_strlen(src));
}
