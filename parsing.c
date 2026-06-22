/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:39:46 by sarrbene          #+#    #+#             */
/*   Updated: 2026/06/22 16:31:05 by achafai          ###   ########.fr       */
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

void	parse_numbers(t_stack **a, int argc, char **argv, int start_indx)
{
	int		i;
	int		j;
	char	**arr;

	i = start_indx;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			arr = ft_split(argv[i], ' ');
			if (!arr || !arr[0])
				exit_error(a, NULL, arr);
			j = 0;
			while (arr[j])
				add_back(a, new_node(strict_atoi(arr[j++], a, arr)));
			free_split(arr);
		}
		else
		{
			if (!ft_is_num(argv[i]))
				exit_error(a, NULL, NULL);
			add_back(a, new_node(strict_atoi(argv[i], a, NULL)));
		}
		i++;
	}
}
