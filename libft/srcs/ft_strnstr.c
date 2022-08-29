/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:34:12 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/03 00:34:12 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	needle_s;
	unsigned int	count;

	needle_s = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (needle[needle_s])
		needle_s++;
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		count = 0;
		while (haystack[i + j] == needle[j] && j < needle_s && i + j < len)
		{
			j++;
			count++;
		}
		if (count == needle_s)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
