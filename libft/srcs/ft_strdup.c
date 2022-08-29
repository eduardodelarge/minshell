/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:11:06 by anjose-d          #+#    #+#             */
/*   Updated: 2022/07/18 14:28:02 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len_s1;
	int		i;

	len_s1 = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[len_s1])
		len_s1++;
	dst = (char *)malloc(sizeof(char) * len_s1 + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
