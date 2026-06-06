/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:09:59 by achafai           #+#    #+#             */
/*   Updated: 2026/05/06 19:12:10 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*l_occurence;

	l_occurence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			l_occurence = (char *)s;
		s++;
	}
	if ('\0' == (char)c)
		return ((char *)s);
	return (l_occurence);
}
