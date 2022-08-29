/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:54:11 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/09 22:45:14 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_s;
	size_t	src_s;

	dst_s = 0;
	src_s = 0;
	i = 0;
	while (src[src_s])
		src_s++;
	if (dstsize == 0)
		return (src_s);
	while (dst_s < dstsize && dst[dst_s])
		dst_s++;
	if (dstsize <= dst_s)
		return (dstsize + src_s);
	i = dst_s;
	j = 0;
	while (i < dstsize - 1 && src[j])
	{
		dst[i++] = src[j];
		j++;
	}
	dst[i] = '\0';
	return (src_s + dst_s);
}
