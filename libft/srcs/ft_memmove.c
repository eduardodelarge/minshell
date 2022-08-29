/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:10:02 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/03 00:10:03 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_d;
	char	*ptr_s;
	int		i;

	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	if (!src && !dst)
		return (0);
	if (src == dst)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i)
		{
			ptr_d[i - 1] = ptr_s[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (ptr_d);
}
