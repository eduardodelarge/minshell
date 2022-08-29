/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:18:49 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/04 16:21:44 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*tail;

	if (!lst || !new)
		return ;
	tail = ft_dlstlast(*lst);
	if (tail)
	{
		tail->next = new;
		new->prev = tail;
	}
	else
		*lst = new;
}
