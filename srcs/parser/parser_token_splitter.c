/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexem_splitter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:04:08 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/21 20:23:55 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tokenizer_split(char *input)
{
	char	**lexems;
	int		qtd;
	int		i;
	int		tk_len;

	lexems = NULL;
	qtd = token_count(input);
	if (qtd <= 0)
		return (NULL);
	lexems = (char **)malloc(sizeof(char *) * (qtd + 1));
	if (!lexems)
		return (NULL);
	i = 0;
	while (i < qtd)
	{
		input = ft_skip_space(input);
		tk_len = get_token_size(input);
		lexems[i] = ft_substr(input, 0, tk_len);
		input += tk_len;
		i++;
	}
	lexems[qtd] = NULL;
	return (lexems);
}
