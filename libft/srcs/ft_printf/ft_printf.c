/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:04:40 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/14 19:16:30 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			ft_subspec_init(t_subspec *flags);
static const char	*ft_subspec(const char *format, t_subspec *flags);
static const char	*ft_get_subspec(const char *format, t_subspec *flags);

static int	ft_fspec(const char *format, va_list args, t_subspec *flags)
{
	int	flen;

	flen = 0;
	if (*format == 'c')
		flen += ft_convert_c(va_arg(args, int), flags);
	else if (*format == 's')
		flen += ft_convert_s(va_arg(args, char *), flags);
	else if (*format == 'p')
		flen += ft_convert_p(va_arg(args, long long), 16, flags);
	else if (*format == 'd' || *format == 'i')
		flen += ft_convert_d_i(va_arg(args, int), 10, flags);
	else if (*format == 'u')
		flen += ft_convert_u(va_arg(args, int), 10, flags);
	else if (*format == 'x')
		flen += ft_convert_x(va_arg(args, t_uint), 16, 'x', flags);
	else if (*format == 'X')
		flen += ft_convert_x(va_arg(args, t_uint), 16, 'X', flags);
	else if (*format == '%')
		flen += write(1, "%", 1);
	return (flen);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_uint			flen;
	t_subspec		subspec;

	va_start(args, format);
	flen = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_subspec(format, &subspec);
			if (!*format)
				break ;
			flen += ft_fspec(format, args, &subspec);
			format++;
		}
		else
		{
			flen += write(1, &*format, 1);
			format++;
		}
	}
	va_end(args);
	return (flen);
}

static void	ft_subspec_init(t_subspec *flags)
{
	flags->is_dot = FALSE;
	flags->is_msign = FALSE;
	flags->is_psign = FALSE;
	flags->is_zero = FALSE;
	flags->is_space = FALSE;
	flags->is_hash = FALSE;
	flags->is_dot = FALSE;
	flags->width = 0;
	flags->precision = 0;
}

static const char	*ft_subspec(const char *format, t_subspec *flags)
{
	ft_subspec_init(flags);
	while (*format && (*format == '-' || *format == '+'
			|| *format == ' ' || *format == '#' || *format == '.'
			|| (*format >= '0' && *format <= '9')))
	{
		format = ft_get_subspec(format, flags);
		format++;
	}
	return (format);
}

static const char	*ft_get_subspec(const char *format, t_subspec *flags)
{
	if (*format == '-')
		flags->is_msign = TRUE;
	else if (*format == '+')
		flags->is_psign = TRUE;
	else if (*format == '0')
		flags->is_zero = TRUE;
	else if (*format == ' ')
		flags->is_space = TRUE;
	else if (*format == '#')
		flags->is_hash = TRUE;
	else if (*format == '.')
	{
		flags->is_dot = TRUE;
		flags->precision = ft_atoi(format);
		while (*(format + 1) >= '0' && *(format + 1) <= '9')
			format++;
	}
	else if (*format >= '0' && *format <= '9')
	{
		flags->width = ft_atoi(format);
		while (*(format + 1) >= '0' && *(format + 1) <= '9')
			format++;
	}
	return (format);
}
