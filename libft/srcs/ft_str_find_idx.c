/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:08:14 by anjose-d          #+#    #+#             */
/*   Updated: 2022/07/11 22:59:02 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_str_find_idx(const char *str, int c)
{
	char	*ptr;
	int		i;
	int		len_s;

	len_s = 0;
	while (str[len_s])
		len_s++;
	ptr = (char *)str;
	i = 0;
	while (i < len_s + 1)
	{
		if (ptr[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
