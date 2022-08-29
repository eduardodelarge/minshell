/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:07:06 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 11:15:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_bin_no_path(t_cmd *cmdtable, t_list **envp);
int		exec_cmd_type(t_cmd *cmd_table, t_list **envp);
int		exec_pipeline_type(t_cmd *cmdtable, t_list **envp);
void	wait_processes(t_list *pipeline);

int	exec_cmdline(t_cmd *cmd_table, t_list **envp)
{
	int		exit;
	int		fd;

	exit = 0;
	fd = -1;
	if (ft_strncmp(cmd_table->type, CMD_COMMAND,
			ft_strlen(CMD_COMMAND) + 1) == 0)
	{
		if (cmd_table->here_doc)
		{
			fd = dup(STDIN_FILENO);
			here_doc(cmd_table->here_doc);
		}
		exit = exec_cmd_type(cmd_table, envp);
		waitpid(-1, NULL, 0);
		dup2(fd, STDIN_FILENO);
		if (fd > 0)
			close(fd);
		
	}	
	else if (ft_strncmp(cmd_table->type, CMD_PIPE,
			ft_strlen(CMD_PIPE) + 1) == 0)
	{
		exit = exec_pipeline_type(cmd_table, envp);
		wait_processes(cmd_table->pipeline);
		restart_terminal(cmd_table);
	}
	return (exit);
}

int	exec_cmd_type(t_cmd *cmd_table, t_list **envp)
{
	int	exit;

	exit = 0;
	if (!cmd_table->name)
		return (exit);
	if (has_path(cmd_table->name->lexem->text))
	{
		if (access(cmd_table->name->lexem->text, F_OK) == 0)
		{
			if (access(cmd_table->name->lexem->text, X_OK) == 0)
				exec_cmd(cmd_table, envp);
			else
				printf_exec_error(cmd_table->name->lexem->text, 126);
		}
		else
			printf_exec_error(cmd_table->name->lexem->text, 127);
	}
	else
	{
		if (is_builtin(cmd_table->name->lexem->text))
			exit = exec_builtin(cmd_table, envp);
		else
			exec_bin_no_path(cmd_table, envp);
	}
	return (exit);
}

int	exec_pipeline_type(t_cmd *cmdtable, t_list **envp)
{
	int		exit;
	int		pipefd[2];
	t_list	*pipeline;

	pipeline = cmdtable->pipeline;
	save_std_fds(&cmdtable);
	if (cmdtable->here_doc)
	{
		here_doc(cmdtable->here_doc);
		waitpid(-1, NULL, 0); // hangando no bin_no_path
	}
	exit = 0;
	while (pipeline)
	{
		if (!pipeline->next)
		{
			dup2(cmdtable->redir->fdout, STDOUT_FILENO);
			close(pipefd[PIPE_WRITE]);
		}
		else
		{
			pipe(pipefd);
			pipe_to_stdfd(pipefd[PIPE_WRITE], STDOUT_FILENO);
		}
		exit = exec_cmd_type(pipeline->content, envp);
		pipeline = pipeline->next;
		pipe_to_stdfd(pipefd[PIPE_READ], STDIN_FILENO);
	}
	return (exit);
}

void	exec_bin_no_path(t_cmd *cmdtable, t_list **envp)
{
	char	*abs_cmdpath;
	char	*f_clean;
	char	*cmd;

	cmd = cmdtable->name->lexem->text;
	abs_cmdpath = get_path(cmd, *envp);
	if (abs_cmdpath && cmd && cmd[0])
	{
		f_clean = cmdtable->name->lexem->text;
		cmdtable->name->lexem->text = ft_strdup(abs_cmdpath);
		free(f_clean);
		free(abs_cmdpath);
		if (access(cmdtable->name->lexem->text, X_OK) == 0)
			exec_cmd(cmdtable, envp);
		else
			printf_exec_error(cmdtable->name->lexem->text, 126);
	}
	else
	{
		if (cmd && !cmd[0])
			ft_putstr_fd("''", STDERR_FILENO);
		else
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmdtable->name->lexem->text, STDERR_FILENO);
		}
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		g_exit_status = 127;
	}
}

void	wait_processes(t_list *pipeline)
{
	int	cmd_qtd;

	cmd_qtd = ft_lstsize(pipeline);
	while (cmd_qtd > 0)
	{
		if (!g_exit_status)
			waitpid(-1, &g_exit_status, 0);
		if (WIFEXITED(g_exit_status))
			g_exit_status = g_exit_status % 255;
		cmd_qtd--;
	}
}
