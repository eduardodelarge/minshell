/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:28:59 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/02 00:42:03 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	src_s;

	src_s = ft_strlen(src);
	if (n > src_s)
		n = src_s;
	dst = (char *)malloc((n + 1) * sizeof(char *));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (dst);
}
