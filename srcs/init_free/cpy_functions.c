/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:36:31 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/25 15:05:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexem	*lexem_cpy(t_lexem *lexem)
{
	t_lexem	*lexem_cpy;

	lexem_cpy = (t_lexem *)malloc(sizeof(t_lexem));
	if (lexem_cpy)
	{
		lexem_cpy->text = ft_strdup(lexem->text);
		lexem_cpy->type = lexem->type;
		lexem_cpy->expansion = expansion_cpy(lexem->expansion);
	}
	else
		return (NULL);
	return (lexem_cpy);
}

t_expansion	*expansion_cpy(t_expansion *expansion)
{
	t_expansion	*expansion_cpy;

	expansion_cpy = NULL;
	if (expansion)
	{
		expansion_cpy = (t_expansion *)malloc(sizeof(t_expansion));
		if (expansion_cpy)
		{
			expansion_cpy->start = expansion->start;
			expansion_cpy->end = expansion->end;
			expansion_cpy->param = ft_strdup(expansion->param);
			expansion_cpy->type = expansion->type;
		}
		else
			return (NULL);
	}
	return (expansion_cpy);
}

t_token	*token_cpy(t_token *token)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token)
	{
		new_token->lexem = lexem_cpy(token->lexem);
		if (token->file)
			new_token->file = lexem_cpy(token->file);
		else
			new_token->file = NULL;
		if (token->eof)
			new_token->eof = lexem_cpy(token->eof);
		else
			new_token->eof = NULL;
	}
	else
		return (NULL);
	return (new_token);
}
