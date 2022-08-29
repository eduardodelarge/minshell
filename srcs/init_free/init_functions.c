/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:34:57 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/25 15:31:49 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_init(t_lexem *lex_cur)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token)
	{
		token->lexem = lex_cur;
		token->file = NULL;
		token->eof = NULL;
	}
	else
		return (NULL);
	return (token);
}

t_cmd	*cmd_init(char *type)
{
	t_cmd	*cmdtable;

	cmdtable = malloc(sizeof(t_cmd));
	cmdtable->type = type;
	cmdtable->raw_input = NULL;
	cmdtable->name = NULL;
	cmdtable->suffix = NULL;
	cmdtable->left = NULL;
	cmdtable->right = NULL;
	cmdtable->pipeline = NULL;
	cmdtable->redir = NULL;
	cmdtable->here_doc = NULL;
	if (ft_strncmp(type, CMD_COMMAND, ft_strlen(CMD_COMMAND) + 1) == 0)
		cmdtable->redir = redir_init();
	return (cmdtable);
}

t_envp	*envp_init(char *envvar_name)
{
	t_envp	*envvar;

	envvar = malloc(sizeof(t_envp));
	envvar->name = ft_strdup(envvar_name);
	envvar->value = NULL;
	return (envvar);
}

t_redir	*redir_init(void)
{
	t_redir	*ret;

	ret = malloc(sizeof(t_redir));
	if (!ret)
		return (NULL);
	ret->fdout = STDOUT_FILENO;
	ret->fdin = STDIN_FILENO;
	return (ret);
}
