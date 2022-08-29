/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:11:40 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/25 01:04:18 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_list *params)
{
	t_token	*first_arg;
	int		exit;

	exit = 0;
	g_exit_status = 0;
	ft_putstr_fd("exit\n", 2);
	if (!params)
		return (-1);
	first_arg = params->content;
	if (ft_is_numeric(first_arg->lexem->text))
	{
		if (ft_lstsize(params) == 1)
		{
			exit = -1;
			g_exit_status = ft_atoi(first_arg->lexem->text) % 256;
		}
		else
			exit = printf_exit_error(NULL, 1);
	}
	else
		exit = printf_exit_error(first_arg->lexem->text, 2);
	return (exit);
}
