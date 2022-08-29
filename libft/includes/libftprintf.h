/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:08:14 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/20 00:37:34 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

int			ft_printf(const char *format, ...);
int			ft_convert_d_i(long long nbr, long long base_n, t_subspec *flags);
int			ft_convert_x(t_uint nbr, t_uint base_n, char x, t_subspec *flags);
int			ft_convert_u(t_uint nbr, t_uint base_n, t_subspec *flags);
int			ft_convert_p(t_ull_type nbr, t_ull_type base_n, t_subspec *flags);
int			ft_convert_c(char c, t_subspec *flags);
int			ft_convert_s(char *str, t_subspec *flags);

int			ft_print_number(t_ull_type nbr, t_ull_type base_n, char *base);
int			ft_print_width(char chr, int i);

#endif
