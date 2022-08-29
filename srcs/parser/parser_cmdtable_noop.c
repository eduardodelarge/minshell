/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmdtable_noop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:38:14 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 11:22:14 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*cmdtable_get_name(t_list *lst_tokens);
t_list	*cmdtable_get_suffix(t_list *lst_tokens, t_token *name);

t_cmd	*parser_cmdtable_noop(t_list *lst_tokens)
{
	t_cmd	*cmdtable;
	t_token	*name;
	t_token	*here_doc;

	cmdtable = NULL;
	if (lst_tokens)
	{
		name = cmdtable_get_name(lst_tokens);
		here_doc = cmdtable_get_heredoc(lst_tokens);
		if (name)
		{
			cmdtable = cmd_init(CMD_COMMAND);
			cmdtable->name = token_cpy(name);
			if (here_doc)
				cmdtable->here_doc = cmdtable_get_hdoc_lst(lst_tokens);
			cmdtable->suffix = cmdtable_get_suffix(lst_tokens, name);
		}
		else if (here_doc)
		{
			cmdtable = cmd_init(CMD_COMMAND);
			cmdtable->here_doc = cmdtable_get_hdoc_lst(lst_tokens);
		}
		else
			return (NULL);
	}
	return (cmdtable);
}

t_token	*cmdtable_get_name(t_list *lst_tokens)
{
	t_token	*token;

	while (lst_tokens)
	{
		token = (t_token *)lst_tokens->content;
		if (ft_strncmp(token->lexem->type, TK_WORD,
				ft_strlen(TK_WORD) + 1) == 0)
			return (token);
		lst_tokens = lst_tokens->next;
	}
	return (NULL);
}

t_list	*cmdtable_get_suffix(t_list *lst_tokens, t_token *name)
{
	t_list	*lst_suffix;
	t_token	*token;

	lst_suffix = NULL;
	while (lst_tokens)
	{
		token = (t_token *)lst_tokens->content;
		if (token != name && !token->eof)
		{
			if (!lst_suffix)
				lst_suffix = ft_lstnew(token_cpy(token));
			else
				ft_lstadd_back(&lst_suffix, ft_lstnew(token_cpy(token)));
		}
		lst_tokens = lst_tokens->next;
	}
	return (lst_suffix);
}
