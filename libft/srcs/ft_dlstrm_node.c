/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrm_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:53:06 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/24 19:14:54 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstrm_node(t_dlist **lst, t_dlist *old_node)
{
	t_dlist	*head;
	t_dlist	*tail;

	if (!lst || !old_node)
		return ;
	head = *lst;
	tail = ft_dlstlast(*lst);
	if (old_node == head)
	{
		(*lst)->prev = NULL;
		(*lst) = (*lst)->next;
		if (*lst)
			(*lst)->prev = NULL;
	}
	else if (old_node == tail)
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	else
	{
		old_node->prev->next = old_node->next;
		old_node->next->prev = old_node->prev;
	}
	free(old_node);
}
