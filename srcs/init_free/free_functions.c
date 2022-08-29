/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:34:10 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 04:00:46 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_lexem(void *lexem)
{
	t_lexem	*l;

	l = lexem;
	if (l)
	{
		if (l->text)
			free(l->text);
		if (l->expansion)
			free_t_expansion(l->expansion);
		free(l);
	}
	lexem = NULL;
}

void	free_t_token(void *token)
{
	t_token	*f_token;

	f_token = (t_token *)token;
	if (f_token)
	{
		if (f_token->lexem)
			free_t_lexem(f_token->lexem);
		if (f_token->file)
			free_t_lexem(f_token->file);
		if (f_token->eof)
			free_t_lexem(f_token->eof);
		free(f_token);
	}
	token = NULL;
}

void	free_t_expansion(void *expansion)
{
	t_expansion	*f_expansion;

	f_expansion = expansion;
	if (f_expansion)
	{
		if (f_expansion->param)
			free(f_expansion->param);
		free(f_expansion);
	}
	expansion = NULL;
}

void	free_t_cmd(void *cmdtable)
{
	t_cmd	*f_cmd;

	f_cmd = cmdtable;
	if (f_cmd)
	{
		f_cmd->type = NULL;
		if (f_cmd->name)
			free_t_token(f_cmd->name);
		if (f_cmd->suffix)
			ft_lstclear(&f_cmd->suffix, free_t_token);
		if (f_cmd->left)
			ft_lstclear(&f_cmd->left, free_t_cmd);
		if (f_cmd->right)
			ft_lstclear(&f_cmd->right, free_t_cmd);
		if (f_cmd->pipeline)
			ft_lstclear(&f_cmd->pipeline, free_t_cmd);
		if (f_cmd->raw_input)
			free(f_cmd->raw_input);
		if (f_cmd->here_doc)
			ft_lstclear(&f_cmd->here_doc, free_t_token);
		free(f_cmd->redir);
		free(f_cmd);
	}
	cmdtable = NULL;
}

void	free_t_envp(void *envp)
{
	t_envp	*f_envp;

	f_envp = envp;
	if (f_envp)
	{
		if (f_envp->name)
			free(f_envp->name);
		if (f_envp->value)
			free(f_envp->value);
		free(f_envp);
	}
	envp = NULL;
}
