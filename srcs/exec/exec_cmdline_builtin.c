/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdline_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:58:29 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 03:57:13 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_builtin(char *cmd, t_cmd *cmdline, t_list **envp);

int	exec_builtin(t_cmd *cmdline, t_list **envp)
{
	char	*cmd;
	int		ret;
	t_redir	*tmp_redir;

	ret = 0;
	cmd = cmdline->name->lexem->text;
	tmp_redir = there_is_redir(cmdline->suffix);
	if (tmp_redir)
	{
		free(cmdline->redir);
		cmdline->redir = tmp_redir;
	}
	if (cmdline->redir->fdout > 0 && cmdline->redir->fdin >= 0)
	{
		ret = do_builtin(cmd, cmdline, envp);
		close_fds(cmdline->redir->fdout, cmdline->redir->fdin);
	}
	return (ret);
}

int	do_builtin(char *cmd, t_cmd *cmdline, t_list **envp)
{
	int		ret;
	t_list	*suffix;

	ret = 0;
	suffix = cmdline->suffix;
	if (ft_strncmp(cmd, ECHO, ft_strlen(ECHO) + 1) == 0)
		ret = ft_echo(suffix, cmdline->redir->fdout, cmdline->raw_input);
	else if (ft_strncmp(cmd, CD, ft_strlen(CD) + 1) == 0)
		ret = ft_cd(suffix, envp);
	if (ft_strncmp(cmd, PWD, ft_strlen(PWD) + 1) == 0)
		ret = ft_pwd(cmdline->redir->fdout);
	else if (ft_strncmp(cmd, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		ret = ft_export(suffix, envp, cmdline->redir->fdout);
	else if (ft_strncmp(cmd, UNSET, ft_strlen(UNSET) + 1) == 0)
		ret = ft_unset(suffix, envp);
	else if (ft_strncmp(cmd, EXIT, ft_strlen(EXIT) + 1) == 0)
		ret = ft_exit(suffix);
	else if (ft_strncmp(cmd, ENV, ft_strlen(ENV) + 1) == 0)
		ret = ft_env(*envp, cmdline->redir->fdout);
	return (ret);
}
