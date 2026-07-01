/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:39:46 by sarrbene          #+#    #+#             */
/*   Updated: 2026/07/01 19:02:45 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	parse_strategy(char *arg, t_bench *bench)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		bench->enabled = 1;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		return (SIMPLE);
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		return (MEDIUM);
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		return (COMPLEX);
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
		return (ADAPTIVE);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
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

void	print_float_fd(float num, int fd)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)num;
	decimal_part = (int)((num - integer_part) * 100);
	ft_putnbr_fd(integer_part, fd);
	ft_putchar_fd('.', fd);
	if (decimal_part < 0)
		decimal_part *= -1;
	if (decimal_part < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(decimal_part, fd);
}

void	print_bench(t_bench *bench, t_strategy strategy, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_float_fd(disorder * 100.0f, 2);
	ft_putstr_fd("%\n", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("[bench] Strategy: SIMPLE / O(n^2)\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("[bench] Strategy: MEDIUM / O(n√n)\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("[bench] Strategy: COMPLEX / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("[bench] Strategy: ADAPTIVE /", 2);
		if (disorder < 0.2f)
			ft_putstr_fd(" O(n^2)\n", 2);
		else if (disorder >= 0.5f)
			ft_putstr_fd(" O(n log n)\n", 2);
		else
			ft_putstr_fd(" O(n√n)\n", 2);
	}
	ft_printf("[bench] total_ops: %d\n", bench->total);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
