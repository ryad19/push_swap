/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:08:10 by achafai           #+#    #+#             */
/*   Updated: 2026/05/11 21:49:20 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD:libft/ft_isalnum.c
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
=======
void	print_error_and_exit(t_stack **stack_a, t_stack **stack_b, char **args, int is_split)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (is_split && args)
		free_matrix(args);
	write(2, "Error\n", 6);
	exit(1);
>>>>>>> 6910700eb8fd3a5accf61139881bbe294c366b8a:error.c
}

