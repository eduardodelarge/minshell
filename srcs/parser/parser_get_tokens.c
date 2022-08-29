/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:50:54 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 06:30:36 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexem		*get_file(t_lexem *file);

t_list	*get_tokens(t_list *lexems)
{
	t_list	*tokens;
	t_lexem	*lex_cpy;
	t_token	*tk_node;

	tokens = NULL;
	while (lexems)
	{
		lex_cpy = lexem_cpy(lexems->content);
		tk_node = token_init(lex_cpy);
		if (is_redir_type(tk_node->lexem->type) && lexems->next)
		{
			tk_node->file = get_file(lexems->next->content);
			lexems = lexems->next;
		}
		if (lexems && lexems->next && ft_strncmp(tk_node->lexem->type, TK_DLESS, ft_strlen(TK_DLESS) + 1) == 0)
		{
			tk_node->eof = lexem_cpy(lexems->next->content);
			lexems = lexems->next;
		}
		if (!tokens)
			tokens = ft_lstnew(tk_node);
		else
			ft_lstadd_back(&tokens, ft_lstnew(tk_node));
		lexems = lexems->next;
	}
	return (tokens);
}

t_lexem	*get_file(t_lexem *file)
{
	t_lexem	*file_cpy;

	file_cpy = NULL;
	if (ft_strncmp(file->type, TK_FILE, ft_strlen(TK_FILE) + 1) == 0)
		file_cpy = lexem_cpy(file);
	return (file_cpy);
}
