/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hundle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 03:13:47 by achafai           #+#    #+#             */
/*   Updated: 2026/06/06 14:48:47 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0/libft.h"

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

int	atoi(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if ((ft_strncmp(str[i], "2147483647", 10) > 0) || (ft_strncmp(str[i],
				"2147483648", 10) > 0))
	{
		exit_error(); //to_be_defined_later;
	}
	return (ft_atoi(str));
}

void	parse_args(char **argv)
{
	int	i;

	
}