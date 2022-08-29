/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:19:13 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/12 05:17:37 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert_c(char c, t_subspec *flags)
{
	int	len_p;

	len_p = 0;
	if (flags->width > 1)
	{
		if (flags->is_msign)
		{
			len_p += write(1, &c, 1);
			len_p += ft_print_width(' ', flags->width - 1);
		}
		else
		{
			if (flags->is_zero)
				len_p += ft_print_width('0', flags->width - 1);
			else
				len_p += ft_print_width(' ', flags->width - 1);
			len_p += write(1, &c, 1);
			return (len_p);
		}
	}
	else
		len_p += write(1, &c, 1);
	return (len_p);
}
