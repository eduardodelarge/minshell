/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:20:24 by anjose-d          #+#    #+#             */
/*   Updated: 2022/07/28 10:58:32 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_first_pos(char c);

int	ft_is_numeric(char *str)
{
	int	i;

	if (str && check_first_pos(str[0]))
	{
		i = 1;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

static int	check_first_pos(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}
