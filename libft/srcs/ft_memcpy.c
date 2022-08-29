/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:09:57 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/03 00:09:58 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;
	size_t	i;

	i = 0;
	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (ptr_d);
}
