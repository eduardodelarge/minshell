/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_idx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:47:08 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 04:50:24 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_idx(char const *s, int idx)
{
	char	**split;
	int		i;

	split = malloc(sizeof(char *) * (2 + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (s[i] && i < idx)
		i++;
	split[0] = ft_substr(s, 0, i);
	split[1] = ft_substr(s, i + 1, ft_strlen(s) - i);
	split[2] = NULL;
	return (split);
}
