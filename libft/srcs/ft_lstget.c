/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:38:21 by anjose-d          #+#    #+#             */
/*   Updated: 2022/07/11 19:38:59 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstget(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst->content);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
