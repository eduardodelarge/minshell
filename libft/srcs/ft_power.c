/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:46:10 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/12 09:46:11 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull_type	ft_power(long long number, long int power)
{
	if (power == 0)
		return (1);
	number *= ft_power(number, power - 1);
	return (number);
}
