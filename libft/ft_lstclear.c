/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:42:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/01 02:05:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		nxt = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = nxt;
	}
	*lst = NULL;
}
