/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deftypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:45:29 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/20 00:37:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFTYPES_H
# define DEFTYPES_H

# include <stdarg.h>
# include <unistd.h>

typedef unsigned long long int	t_ull_type;
typedef unsigned int			t_uint;

typedef enum e_bool {
	FALSE,
	TRUE
}			t_bool;

typedef struct s_subspec
{
	t_bool	is_msign;
	t_bool	is_psign;
	t_bool	is_zero;
	t_bool	is_space;
	t_bool	is_hash;
	t_bool	is_dot;
	size_t	width;
	size_t	precision;
}	t_subspec;

#endif
