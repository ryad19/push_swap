/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achafai <achafai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:02:03 by achafai           #+#    #+#             */
/*   Updated: 2026/05/12 19:21:37 by achafai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cpy = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(cpy, del);
	}
}
