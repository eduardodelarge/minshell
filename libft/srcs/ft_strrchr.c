/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:11:52 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/04 15:50:04 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	*lst_occ;
	int		s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	ptr = (char *)s;
	lst_occ = 0;
	i = 0;
	while (i < s_len + 1)
	{
		if (ptr[i] == (char)c)
			lst_occ = &ptr[i];
		i++;
	}
	return (lst_occ);
}
