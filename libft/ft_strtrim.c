/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 06:30:05 by achafai           #+#    #+#             */
/*   Updated: 2026/05/13 03:32:36 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;

	if (*s1 == '\0')
		return (ft_strdup(""));
	if (*set == '\0')
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && in_set(s1[start], set))
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (end > start && in_set(s1[end], set))
		end--;
	p = (char *)malloc((end - start + 2) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1 + start, end - start + 2);
	return (p);
}
