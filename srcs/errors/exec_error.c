/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:15:18 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/21 19:10:53 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_error(void)
{
	perror("pipe");
	exit(EXIT_FAILURE);
}

void	fork_error(void)
{
	perror("fork");
	exit(EXIT_FAILURE);
}

int	printf_openfile_error(char *file, char *msg)
{
	int	ret;

	ret = -1;
	g_exit_status = 1;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (ret);
}
