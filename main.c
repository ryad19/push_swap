/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:27:24 by achafai           #+#    #+#             */
/*   Updated: 2026/06/22 16:59:49 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_flag(char **argv, t_bench *bench, t_strategy *strategy)
{
	int	i;

	i = 1;
	while (i < 3 && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			bench->enabled = 1;
		else
			*strategy = parse_strategy(argv[i]);
		i++;
	}
	return (i);
}

int	main(int argc, char const *argv[])
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_strategy	strategy;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	bench = (t_bench){0};
	strategy = ADAPTIVE;
	i = handle_flag(argv, &bench, &strategy);
	parse_numbers(&a, argc, argv, i);
	return (0);
}
