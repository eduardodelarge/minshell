/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:03:41 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/07 21:03:41 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nelem;

	nelem = malloc(sizeof(t_list));
	if (!nelem)
		return (0);
	nelem->content = content;
	nelem->next = NULL;
	return (nelem);
}
