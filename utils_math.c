/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:21:06 by achafai           #+#    #+#             */
/*   Updated: 2026/06/19 12:02:36 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	pairs;
	t_stack	*end;
	t_stack	*temp;

	if (!a || (a->next == a))
		return (0.0f);
	end = a->prev;
	mistakes = 0;
	pairs = 0;
	while (a != end)
	{
		temp = a->next;
		while (temp != end->next)
		{
			pairs += 1;
			if (a->value > temp->value)
				mistakes += 1;
			temp = temp->next;
		}
		a = a->next;
	}
	return (mistakes / pairs);
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	strict_atoi(char *str, t_stack **a)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = (num * 10) + (*str - 48);
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			handle_error(a, NULL);
		str++;
	}
	return ((int)(num * sign));
<<<<<<< HEAD:utils_math.c
}
=======
}

void	parse_args(char **argv, int argc, t_stack	**stack)
{
	int		i;
	int		content;
	t_stack	*head;

	head = *stack;
	if (argc < 2)
		handle_error(NULL, NULL);
	i = 0;
	while (i + 1 < argc)
	{
		if (!ft_is_num(argv[i + 1]))
			handle_error(stack, NULL);
		content = strict_atoi(argv[i], stack);
		if (has_duplicate(content, head))
			handle_error(stack, NULL);
		add_back(stack, new_node(content, i));
		i++;
	}
}
>>>>>>> 039a3be7f5d43482f30bda07b8f11652273dada6:input_handle.c
