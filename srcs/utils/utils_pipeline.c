/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:14:47 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/23 17:33:20 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_std_fds(t_cmd **cmdtable)
{
	t_redir	*std_fds;
	t_redir	*cur_fds;

	cur_fds = (*cmdtable)->redir;
	if (cur_fds)
		free(cur_fds);
	std_fds = redir_init();
	std_fds->fdin = dup(std_fds->fdin);
	std_fds->fdout = dup(std_fds->fdout);
	(*cmdtable)->redir = std_fds;
}

void	restart_terminal(t_cmd *cmdtable)
{
	dup2(cmdtable->redir->fdin, STDIN_FILENO);
	dup2(cmdtable->redir->fdout, STDOUT_FILENO);
	close(cmdtable->redir->fdin);
	close(cmdtable->redir->fdout);
}

void	pipe_to_stdfd(int pipefd, int stdfd)
{
	dup2(pipefd, stdfd);
	close(pipefd);
}
