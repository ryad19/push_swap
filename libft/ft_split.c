/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:09:13 by achafai           #+#    #+#             */
/*   Updated: 2026/05/23 15:05:53 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftstrlen(const char *str, char c)
{
	int	sum;

	sum = 0;
	while (str[sum] != c && str[sum])
		sum++;
	return (sum);
}

static int	count_words(const char *s, char **tab, char c)
{
	int	w_count;
	int	word;

	if (!s)
		return (0);
	w_count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (word == 0)
			{
				if (tab)
					tab[w_count] = (char *)s;
				w_count++;
				word = 1;
			}
		}
		else
			word = 0;
		s++;
	}
	return (w_count);
}

static char	**free_all(char **matrix, char **tab, int count)
{
	while (count > 0)
	{
		count--;
		free(matrix[count]);
	}
	free(matrix);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w_num;
	char	**t_ptr;
	char	**output;

	if (!s)
		return (NULL);
	w_num = count_words(s, NULL, c);
	t_ptr = malloc(sizeof(char *) * (w_num + 1));
	output = malloc(sizeof(char *) * (w_num + 1));
	if (!t_ptr || !output)
		return (free_all(output, t_ptr, 0));
	count_words(s, t_ptr, c);
	i = 0;
	while (i < w_num)
	{
		output[i] = malloc(sizeof(char) * (ftstrlen(t_ptr[i], c) + 1));
		if (!output[i])
			return (free_all(output, t_ptr, i));
		ft_strlcpy(output[i], t_ptr[i], ftstrlen(t_ptr[i], c) + 1);
		i++;
	}
	output[w_num] = NULL;
	free(t_ptr);
	return (output);
}
