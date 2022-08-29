/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:23:34 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/04 16:51:24 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;
	t_dlist	*old_elem;

	if (!del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		old_elem = tmp;
		tmp = old_elem->next;
		del(old_elem);
	}
	*lst = NULL;
}
