/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:11:37 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/09 22:46:11 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_o;
	int		i;
	int		slen;

	if (!s)
		return (0);
	slen = 0;
	while (s[slen])
		slen++;
	str_o = (char *)malloc(sizeof(char) * (slen + 1));
	if (!str_o)
		return (0);
	i = 0;
	while (s[i])
	{
		str_o[i] = f(i, s[i]);
		i++;
	}
	str_o[i] = '\0';
	return (str_o);
}
