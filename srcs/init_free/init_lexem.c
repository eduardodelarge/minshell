/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:47:54 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 15:25:14 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*lexem_get_type(char *text);

t_lexem	*lexem_init(char *text)
{
	t_lexem	*lexem;

	lexem = (t_lexem *)malloc(sizeof(t_lexem));
	if (lexem)
	{
		lexem->text = ft_strdup(text);
		lexem->type = lexem_get_type(text);
		lexem->expansion = expansion_init(text);
	}
	else
		return (NULL);
	return (lexem);
}

static char	*lexem_get_type(char *text)
{
	char	*type;

	type = TK_WORD;
	if (text)
	{
		if (ft_strncmp(text, ">", ft_strlen(text) + 1) == 0)
			type = TK_GREAT;
		else if (ft_strncmp(text, "<", ft_strlen(text) + 1) == 0)
			type = TK_LESS;
		else if (ft_strncmp(text, "|", ft_strlen(text) + 1) == 0)
			type = TK_PIPE;
		else if (ft_strncmp(text, "||", ft_strlen(text) + 1) == 0)
			type = TK_OR;
		else if (ft_strncmp(text, "&", ft_strlen(text) + 1) == 0)
			type = TK_ASYNC;
		else if (ft_strncmp(text, "&&", ft_strlen(text) + 1) == 0)
			type = TK_AND;
		else if (ft_strncmp(text, "<<", ft_strlen(text) + 1) == 0)
			type = TK_DLESS;
		else if (ft_strncmp(text, ">>", ft_strlen(text) + 1) == 0)
			type = TK_DGREAT;
	}
	return (type);
}
