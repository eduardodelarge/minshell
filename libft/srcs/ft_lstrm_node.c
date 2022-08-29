/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:16:38 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/14 03:25:49 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm_node(t_list **lst, t_list *old_node)
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !old_node)
		return ;
	head = *lst;
	if (old_node == head)
		(*lst) = (*lst)->next;
	else
	{
		tmp = head;
		while (tmp && tmp->next != old_node)
			tmp = tmp->next;
		tmp->next = old_node->next;
	}
}
