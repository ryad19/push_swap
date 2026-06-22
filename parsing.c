/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:39:46 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/22 12:33:46 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	parse_strategy(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (COMPLEX);
	return (ADAPTIVE);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*end;

	if (!stack || stack->next == stack)
		return (0);
	end = stack->prev;
	while (stack != end)
	{
		temp = stack->next;
		while (temp != end->next)
		{
			if (stack->value == temp->value)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	parse_numbers(t_stack **a, int argc, char **argv, t_bench *bench,
		t_strategy *x)
{
	int		i;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_strncmp(argv[i], "--bench", 7) == 0)
			{
				bench->enabled = 1;
				i++;
			}
			*x = parse_strategy(argv[i]);
			i++;
		}
		if (ft_strchr(argv[i], ' '))
			arr = ft_split(argv[i], ' ');
	}
}
