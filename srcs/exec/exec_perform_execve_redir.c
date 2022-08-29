/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_perform_execve_redir.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:06:01 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 05:04:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_exec(t_cmd *cmdline, char **mtx_cmdline, char **envp);

void	perform_execve_redir(t_cmd *cmdtable, t_list **envp)
{
	char	**mtx_envp;
	char	**cmdline;
	int		pid;
	int		status;

	cmdline = cmdline2mtx_redir(cmdtable);
	mtx_envp = lst2mtx_envp(*envp);
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
		child_exec(cmdtable, cmdline, mtx_envp);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		g_exit_status = status % 255;
	ft_destroy_matrix(mtx_envp);
	ft_destroy_matrix(cmdline);
}

static void	child_exec(t_cmd *cmdline, char **mtx_cmdline, char **envp)
{
	int		ret;
	char	*cmd;

	cmd = cmdline->name->lexem->text;
	ret = 0;
	if (cmdline->redir && cmdline->redir->fdin > 2)
	{
		dup2(cmdline->redir->fdin, STDIN_FILENO);
		close(cmdline->redir->fdin);
	}
	if (cmdline->redir && cmdline->redir->fdout > 2)
	{
		dup2(cmdline->redir->fdout, STDOUT_FILENO);
		close(cmdline->redir->fdout);
	}
	ret = execve(cmd, mtx_cmdline, envp);
	if (!ret)
		exit(EXIT_FAILURE);
}
