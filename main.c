/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:27:24 by achafai           #+#    #+#             */
/*   Updated: 2026/06/27 19:58:37 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_stack **a, t_stack **b, t_bench *bench,
		t_strategy strategy, float disorder)
{
	if (strategy == SIMPLE || (stack_size(*a) <= 5))
		sort_simple(a, b, bench);
	else if (strategy == MEDIUM)
		sort_medium(a, b, bench);
	else if (strategy == COMPLEX)
		sort_complex(a, b, bench);
	else if (disorder < 0.2f)
		sort_simple(a, b, bench);
	else if (disorder >= 0.5f)
		sort_complex(a, b, bench);
	else
		sort_medium(a, b, bench);
}

static int	handle_flag(char **argv, t_bench *bench, t_strategy *strategy)
{
	int	i;
	int	index;

	i = 1;
	index = 1;
	while (i < 3)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_strncmp(argv[i], "--bench", 8) == 0)
			{
				bench->enabled = 1;
				i++;
				index++;
			}
			else
			{
				*strategy = parse_strategy(argv[i]);
				i++;
				index++;
			}
		}
		i++;
	}
	return (index);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_strategy	strategy;
	float		disorder;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	bench = (t_bench){0};
	strategy = ADAPTIVE;
	i = handle_flag(argv, &bench, &strategy);
	parse_numbers(&a, argc, argv, i);
	disorder = compute_disorder(a);
	run_strategy(&a, &b, &bench, strategy, disorder);
	return (0);
}
