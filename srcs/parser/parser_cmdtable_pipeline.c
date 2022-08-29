/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmdtable_pipeline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:38:14 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 15:12:21 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_cmdline(t_list *lst_tokens);
t_list	*get_pipe_node(t_list *lst_tokens);
t_list	*get_cmdline_pipeline(t_list *head, t_list *pipe_node);

t_cmd	*parser_cmdtable_pipeline(t_list *lst_tokens)
{
	t_cmd	*cmdtable;
	t_cmd	*cmdline_node;
	t_list	*cmdline;
	t_list	*pipe_node;

	cmdtable = cmd_init(CMD_PIPE);
	if (cmdtable_get_heredoc(lst_tokens))
		cmdtable->here_doc = cmdtable_get_hdoc_lst(lst_tokens);
	while (lst_tokens)
	{
		pipe_node = get_pipe_node(lst_tokens);
		cmdline = get_cmdline_pipeline(lst_tokens, pipe_node);
		if (!cmdtable_get_heredoc(cmdline))
		{
			cmdline_node = parser_cmdtable_noop(cmdline);
			if (!cmdtable->pipeline)
				cmdtable->pipeline = ft_lstnew(cmdline_node);
			else
				ft_lstadd_back(&cmdtable->pipeline, ft_lstnew(cmdline_node));
		}
		lst_tokens = pipe_node;
		if (lst_tokens)
			lst_tokens = lst_tokens->next;
		ft_lstclear(&cmdline, free_t_token);
	}
	return (cmdtable);
}

t_list	*get_cmdline(t_list *lst_tokens)
{
	t_list	*cmdline;
	t_token	*tk_node;

	cmdline = NULL;
	tk_node = NULL;
	while (lst_tokens)
	{
		tk_node = lst_tokens->content;
		if (ft_strncmp(tk_node->lexem->type, TK_PIPE,
				ft_strlen(TK_PIPE) + 1) == 0)
			break ;
		tk_node = token_cpy(lst_tokens->content);
		if (!cmdline)
			cmdline = ft_lstnew(tk_node);
		else
			ft_lstadd_back(&cmdline, ft_lstnew(tk_node));
		lst_tokens = lst_tokens->next;
	}
	return (cmdline);
}

/* Find and returns the pipe's token node */
t_list	*get_pipe_node(t_list *lst_tokens)
{
	t_list	*lst_pipe_node;
	t_token	*tk;

	lst_pipe_node = lst_tokens;
	while (lst_pipe_node)
	{
		tk = lst_pipe_node->content;
		if (ft_strncmp(tk->lexem->type, TK_PIPE,
				ft_strlen(TK_PIPE) + 1) == 0)
			break ;
		lst_pipe_node = lst_pipe_node->next;
	}
	return (lst_pipe_node);
}

/* Function to get the cmdline between pipes */
t_list	*get_cmdline_pipeline(t_list *head, t_list *pipe_node)
{
	t_list	*cmdline;

	cmdline = NULL;
	while (head)
	{
		if (head == pipe_node)
			break ;
		if (!cmdline)
			cmdline = ft_lstnew(token_cpy(head->content));
		else
			ft_lstadd_back(&cmdline, ft_lstnew(token_cpy(head->content)));
		head = head->next;
	}
	return (cmdline);
}

