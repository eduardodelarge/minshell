/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:32:37 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/12 09:50:50 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_putnstr(char *str, int size);
static size_t	ft_strlen_printf(char *str);

int	ft_convert_s(char *str, t_subspec *flags)
{
	size_t	len_str;
	size_t	len_p;

	len_p = 0;
	len_str = ft_strlen_printf(str);
	if (flags->is_dot && flags->precision < len_str)
		len_str = flags->precision;
	if (flags->width > len_str)
	{
		if (flags->is_msign)
		{
			len_p += ft_putnstr(str, len_str);
			len_p += ft_print_width(' ', flags->width - len_str);
			return (len_p);
		}
		else if (flags->is_zero)
			ft_print_width('0', flags->width - len_str);
		else
			ft_print_width(' ', flags->width - len_str);
		ft_putnstr(str, len_str);
		len_p = flags->width;
	}
	else
		len_p += ft_putnstr(str, len_str);
	return (len_p);
}

static int	ft_putnstr(char *str, int size)
{
	int		i;
	char	*null_str;

	null_str = "(null)";
	i = 0;
	if (!str)
	{
		while (i < size && null_str[i])
			i += write(1, &null_str[i], 1);
		return (i);
	}
	while (str[i] && i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static size_t	ft_strlen_printf(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (6);
	while (str[len])
		len++;
	return (len);
}
