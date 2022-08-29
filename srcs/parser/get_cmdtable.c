/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:56:31 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/27 17:02:48 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd		*set_cmdtable_type(t_list *lst_tokens);
static void	clean_structs(char **mtx_tks, t_list **lexems, t_list **tokens);

t_cmd	*get_cmdtable(char *input, t_list *envp)
{
	t_cmd	*cmdtable;
	char	**tokens_split;
	t_list	*lst_lexems;
	t_list	*lst_tokens;

	cmdtable = NULL;
	lst_tokens = NULL;
	if (input && input[0])
	{
		tokens_split = tokenizer_split(input);
		lst_lexems = lexem_tagging(tokens_split);
		if (lst_lexems)
		{
			ft_lex_expander(&lst_lexems, envp);
			if (!check_syntax_error(lst_lexems))
			{
				rm_quote_from_lexems(&lst_lexems);
				lst_tokens = get_tokens(lst_lexems);
				cmdtable = set_cmdtable_type(lst_tokens);
				if (cmdtable)
					cmdtable->raw_input = ft_strdup(input);
			}
		}
		clean_structs(tokens_split, &lst_lexems, &lst_tokens);
	}
	return (cmdtable);
}

t_cmd	*set_cmdtable_type(t_list *lst_tokens)
{
	t_cmd	*cmdtable;
	t_list	*tmp;
	t_token	*node;

	cmdtable = NULL;
	tmp = lst_tokens;
	while (tmp)
	{
		node = tmp->content;
		if (ft_strncmp(node->lexem->type, TK_PIPE, ft_strlen(TK_PIPE) + 1) == 0)
		{
			cmdtable = parser_cmdtable_pipeline(lst_tokens);
			break ;
		}
		tmp = tmp->next;
	}
	if (!cmdtable)
		cmdtable = parser_cmdtable_noop(lst_tokens);
	return (cmdtable);
}

void	clean_structs(char **mtx_tks, t_list **lexems, t_list **tokens)
{
	ft_destroy_matrix(mtx_tks);
	ft_lstclear(lexems, &free_t_lexem);
	ft_lstclear(tokens, &free_t_token);
}
