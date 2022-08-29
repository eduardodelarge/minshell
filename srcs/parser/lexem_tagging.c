/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_tagging.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:03:49 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 01:48:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lexem_tagging(char **mtx_lexems)
{
	t_list	*lst_lexems;
	t_lexem	*new_lexem;
	t_lexem	*prev_lex;
	int		i;

	lst_lexems = NULL;
	i = 0;
	if (!mtx_lexems)
		return (NULL);
	while (mtx_lexems[i])
	{
		new_lexem = lexem_init(mtx_lexems[i]);
		if (i != 0)
		{
			if (is_redir_type(prev_lex->type))
				new_lexem->type = TK_FILE;
		}
		if (!lst_lexems)
			lst_lexems = ft_lstnew(new_lexem);
		else
			ft_lstadd_back(&lst_lexems, ft_lstnew(new_lexem));
		prev_lex = new_lexem;
		i++;
	}
	return (lst_lexems);
}
