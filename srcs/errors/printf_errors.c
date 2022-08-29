/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:01:04 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 05:05:32 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printf_export_error(char *param)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(param, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd("not a valid identifier\n", 2);
	g_exit_status = 1;
}

void	printf_unset_error(char *param)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(param, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd("not a valid identifier\n", 2);
	g_exit_status = 1;
}

int	printf_exit_error(char *param, int exit_status)
{
	if (exit_status == 1)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		g_exit_status = exit_status;
	}
	else if (exit_status == 2)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(param, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("numeric argument required\n", 2);
		g_exit_status = exit_status;
		return (-1);
	}
	return (0);
}

void	printf_cd_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd("too many arguments\n", 2);
	g_exit_status = 1;
}

void	printf_exec_error(char *param, int exit_status)
{
	if (exit_status == 126)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(param, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(ERR_NOPERM, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	else if (exit_status == 127)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(param, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(ERR_FNOEXST, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	g_exit_status = exit_status;
}
