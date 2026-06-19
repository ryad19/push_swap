/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 03:13:47 by achafai           #+#    #+#             */
/*   Updated: 2026/06/19 10:43:31 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "print/ft_printf.h"
#include "push_swap.h"


void	parse_args(char **argv, int argc, t_stack	**stack)
{
	int		i;
	char	**str;

	if (argc < 2)
		handle_error(NULL, NULL);
	i = 0;
	if (argc <= 4)
		while (++i < argc)
			if (!is_flag(argv[i]))
			{
				str = ft_split(argv[i], ' ');
				while (*str)
				{
					if (!ft_is_num(*str))
						handle_error(NULL, NULL);
					add_back(stack, new_node(strict_atoi(str, stack)));
					str++;
				}
			}
	while (++i < argc)
		if (!ft_is_num(argv[i]))
			if (!is_flag(argv[i]))
				handle_error(NULL,NULL);
		else
			add_back(stack, new_node(strict_atoi(argv[i], stack)));
}

int	is_flag(char *flag)
{
	if (!ft_strncmp(flag, "--simple", ft_strlen("--simple")))
		return (1);
	if (!ft_strncmp(flag, "--medium", ft_strlen("--medium")))
		return (1);
	if (!ft_strncmp(flag, "--complex", ft_strlen("--complex")))
		return (1);
	if (!ft_strncmp(flag, "--adaptive", ft_strlen("--adaptive")))
		return (1);
	if (!ft_strncmp(flag, "--bench", ft_strlen("--bench")))
		return (1);
	return (0);
}