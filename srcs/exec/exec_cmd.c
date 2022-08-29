/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:26:14 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/23 00:31:27 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_cmd *cmdtable, t_list **envp)
{
	if (!cmdline_has_redir(cmdtable))
		perform_execve_normal(cmdtable, envp);
	else
	{
		cmdtable->redir = there_is_redir(cmdtable->suffix);
		if (cmdtable->redir->fdin > 0 || cmdtable->redir->fdout > 0)
			perform_execve_redir(cmdtable, envp);
	}
}
