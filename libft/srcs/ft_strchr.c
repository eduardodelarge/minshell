/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:11:01 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/04 15:46:47 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	int		len_s;

	len_s = 0;
	while (s[len_s])
		len_s++;
	ptr = (char *)s;
	i = 0;
	while (i < len_s + 1)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	return (ptr = 0);
}
