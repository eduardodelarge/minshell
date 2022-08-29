/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:24:18 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/12 17:59:47 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_number(t_ull_type nbr, t_ull_type base_n, char *base)
{
	int			nbr_s;
	int			ret;
	t_ull_type	tmp;
	t_ull_type	n_print;

	nbr_s = 1;
	ret = 0;
	tmp = nbr;
	while (tmp >= base_n)
	{
		nbr_s++;
		tmp /= base_n;
	}
	while (--nbr_s >= 0)
	{
		n_print = (nbr / ft_power(base_n, nbr_s));
		write(1, &base[n_print], 1);
		nbr %= ft_power(base_n, nbr_s);
		ret++;
	}
	return (ret);
}

int	ft_print_width(char chr, int i)
{
	int	count;

	count = 0;
	while (i > 0)
	{
		count += write(1, &chr, 1);
		i--;
	}
	return (count);
}
