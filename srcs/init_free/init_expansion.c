/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:49:52 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 02:32:54 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expansion_get_type(char *param);
static void	get_expansion(t_expansion **expansion, char *lex_text);

t_expansion	*expansion_init(char *lex_text)
{
	t_expansion	*expansion;

	if (!is_expansion(lex_text))
		return (NULL);
	else
	{
		expansion = (t_expansion *)malloc(sizeof(t_expansion));
		if (!expansion)
			return (NULL);
		else
			get_expansion(&expansion, lex_text);
	}
	return (expansion);
}

static char	*expansion_get_type(char *param)
{
	char	*type;

	type = NULL;
	if (param)
	{
		if (param[0] == '?')
			type = EXP_EXIT_STATUS;
		else
			type = EXP_ENVVAR;
	}
	return (type);
}

static void	get_expansion(t_expansion **expansion, char *lex_text)
{
	int		quotes;
	char	*tmp;

	quotes = 0;
	tmp = NULL;
	while (is_quote_apst(lex_text[0]) && is_quote_apst(lex_text[ft_strlen(lex_text) - 1]))
	{
		tmp = lex_text;
		lex_text = ft_rm_quotation(lex_text);
		if (quotes)
			free(tmp);
		quotes++;
	}
	(*expansion)->start = ft_str_find_idx(lex_text, '$');
	if (lex_text[(*expansion)->start + 1] == '?')
		(*expansion)->end = (*expansion)->start + 1;
	else
		(*expansion)->end = ft_strlen(lex_text) - 1;
	(*expansion)->param = ft_substr(lex_text, (*expansion)->start + 1, (*expansion)->end);
	(*expansion)->type = expansion_get_type((*expansion)->param);
	if (quotes)
		free(lex_text);
	(*expansion)->start += quotes;
	(*expansion)->end += quotes;
}
