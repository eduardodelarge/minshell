/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:21:09 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 12:10:36 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*cmdtable_get_heredoc(t_list *lst_tokens)
{
	t_token	*token;

	while (lst_tokens)
	{
		token = (t_token *)lst_tokens->content;
		if (ft_strncmp(token->lexem->type, TK_DLESS,
				ft_strlen(TK_DLESS) + 1) == 0)
			return (token);
		lst_tokens = lst_tokens->next;
	}
	return (NULL);
}

t_list	*cmdtable_get_hdoc_lst(t_list *lst_tokens)
{
	t_list	*lst_suffix;
	t_token	*token;

	lst_suffix = NULL;
	while (lst_tokens)
	{
		token = (t_token *)lst_tokens->content;
		if (token->eof)
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

