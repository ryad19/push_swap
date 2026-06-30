/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:27:24 by achafai           #+#    #+#             */
/*   Updated: 2026/06/30 12:24:31 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	run_strategy(t_stack **a, t_stack **b, t_bench *bench,
		t_sort_ctx *ctx)
{
	if (ctx->strategy == SIMPLE || (stack_size(*a) <= 5))
		sort_simple(a, b, bench);
	else if (ctx->strategy == MEDIUM)
		sort_medium(a, b, bench);
	else if (ctx->strategy == COMPLEX)
		sort_complex(a, b, bench);
	else if (ctx->disorder < 0.2f)
		sort_simple(a, b, bench);
	else if (ctx->disorder >= 0.5f)
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
				index++;
			}
			else
			{
				*strategy = parse_strategy(argv[i]);
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
	t_sort_ctx	ctx;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	bench = (t_bench){0};
	ctx.strategy = ADAPTIVE;
	i = handle_flag(argv, &bench, &ctx.strategy);
	parse_numbers(&a, argc, argv, i);
	if (has_duplicates(a))
		exit_error(&a, NULL, NULL);
	assign_indx(a);
	ctx.disorder = compute_disorder(a);
	run_strategy(&a, &b, &bench, &ctx);
	if (bench.enabled)
		print_bench(&bench, ctx.strategy, ctx.disorder);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
