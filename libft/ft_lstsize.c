/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 07:06:10 by achafai           #+#    #+#             */
/*   Updated: 2026/05/02 16:13:05 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cpy;
	int		sum;

	cpy = lst;
	sum = 0;
	while (cpy)
	{
		sum++;
		cpy = cpy->next;
	}
	return (sum);
}
