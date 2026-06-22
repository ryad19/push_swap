/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:27:24 by achafai           #+#    #+#             */
/*   Updated: 2026/06/22 12:11:02 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	int			indx;
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_strategy	strategy;

	if (argc < 2)
		return (0);
	indx = 1;
	if (argv[1][0] == '-')
		if (ft_strncmp(argv[1], "--bench", 7) == 0)
		{
			bench.enabled = 1;
			strategy = parse_strategy(argv[2]);
		}
		else
			strategy = parse_strategy(argv[1]);
	
	return (0);
}
