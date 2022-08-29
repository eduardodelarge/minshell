/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_perform_execve_normal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:53:48 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/25 07:08:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_exec(char *cmd, char **cmdline, char **envp);

void	perform_execve_normal(t_cmd *cmdtable, t_list **envp)
{
	char	**mtx_envp;
	char	**cmdline;
	int		pid;

	cmdline = NULL;
	cmdline = cmdline2mtx_normal(cmdtable);
	mtx_envp = lst2mtx_envp(*envp);
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
		child_exec(cmdtable->name->lexem->text, cmdline, mtx_envp);
	ft_destroy_matrix(mtx_envp);
	ft_destroy_matrix(cmdline);
}

static void	child_exec(char *cmd, char **cmdline, char **envp)
{
	int	ret;

	ret = 0;
	ret = execve(cmd, cmdline, envp);
	if (!ret)
		exit(EXIT_FAILURE);
}
