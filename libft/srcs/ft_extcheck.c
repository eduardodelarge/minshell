/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:09:54 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/29 22:12:17 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_extcheck(char *argv_map, char *ext)
{
	int	map_len;
	int	ext_len;

	map_len = ft_strlen(argv_map);
	ext_len = ft_strlen(ext);
	while (--ext_len)
	{
		map_len -= 1;
		if (argv_map[map_len] != ext[ext_len])
			return (1);
	}
	return (0);
}
