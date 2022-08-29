/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:11:15 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/03 00:11:16 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*ret;
	int				i;

	if (!s1 || !s2)
		return (0);
	len_s1 = (ft_strlen(s1));
	len_s2 = (ft_strlen(s2));
	ret = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		ret[len_s1 + i] = s2[i];
		i++;
	}
	ret[len_s1 + i] = '\0';
	return (ret);
}
