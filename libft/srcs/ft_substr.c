/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:12:03 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/23 00:03:22 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	size_m;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if ((s_len - start) < len)
		size_m = (s_len - start);
	else
		size_m = len;
	subs = (char *)malloc(sizeof(char) * (size_m + 1));
	if (!subs)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = (char)s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
