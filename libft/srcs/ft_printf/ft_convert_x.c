/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:03:17 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/12 09:51:33 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_hex(t_uint nbr, char c, t_subspec *flags);
static int	ft_put_nbr_hexa(t_uint nbr, char x, t_subspec *flags);
static int	ft_hexa_printing(t_uint nbr, char x, t_subspec *flags);

int	ft_convert_x(t_uint nbr, t_uint base_n, char x, t_subspec *flags)
{
	size_t	print_s;
	size_t	nbr_s;

	nbr_s = ft_nbrsize(nbr, base_n);
	print_s = 0;
	if (flags->precision > nbr_s || (flags->is_dot && nbr == 0))
		nbr_s = flags->precision;
	if (flags->width > nbr_s)
	{
		if (flags->is_msign)
		{
			print_s += ft_hexa_printing(nbr, x, flags);
			print_s += ft_print_width(' ', flags->width - nbr_s);
			return (print_s);
		}
		else if (flags->is_zero && !flags->is_dot)
			print_s += ft_print_width('0', flags->width - nbr_s);
		else
			print_s += ft_print_width(' ', flags->width - nbr_s);
		print_s += ft_hexa_printing(nbr, x, flags);
	}
	else
		print_s += ft_hexa_printing(nbr, x, flags);
	return (print_s);
}

static int	ft_print_hex(t_uint nbr, char c, t_subspec *flags)
{
	int		ret;
	size_t	nbr_s;

	ret = 0;
	nbr_s = ft_nbrsize(nbr, 16);
	if (flags->is_hash && nbr > 0)
	{
		write(1, "0", 1);
		write(1, &c, 1);
		if (!flags->is_dot)
			ret += 2;
	}
	if (flags->is_dot && nbr == 0 && flags->precision == 0)
		return (0);
	if (flags->precision > nbr_s)
		ret += ft_print_width('0', flags->precision - nbr_s);
	return (ret);
}

static int	ft_put_nbr_hexa(t_uint nbr, char x, t_subspec *flags)
{
	int	ret;

	ret = 0;
	if (flags->is_dot && nbr == 0 && flags->precision == 0)
		return (0);
	if (x == 'x')
		ret = ft_print_number(nbr, 16, "0123456789abcdef");
	if (x == 'X')
		ret = ft_print_number(nbr, 16, "0123456789ABCDEF");
	return (ret);
}

static int	ft_hexa_printing(t_uint nbr, char x, t_subspec *flags)
{
	int	size_print;

	size_print = 0;
	size_print += ft_print_hex(nbr, x, flags);
	size_print += ft_put_nbr_hexa(nbr, x, flags);
	return (size_print);
}
