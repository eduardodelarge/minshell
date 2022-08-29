/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:38:42 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 06:45:38 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_syntax_error(char *lexem);
int		no_word_token(t_list *lexems);
int		redir_without_file(t_list *lexems);

int	check_syntax_error(t_list *lst_lexems)
{
	t_lexem	*node_lex;
	int		ret;

	node_lex = ft_lstget(lst_lexems, 0);
	ret = 0;
	if (no_word_token(lst_lexems)
		|| (ft_strncmp(node_lex->type, TK_PIPE, ft_strlen(TK_PIPE) + 1) == 0
		|| ft_strncmp(node_lex->type, TK_OR, ft_strlen(TK_OR) + 1) == 0
		|| ft_strncmp(node_lex->type, TK_AND, ft_strlen(TK_AND) + 1) == 0
		|| ft_strncmp(node_lex->type, TK_ASYNC, ft_strlen(TK_ASYNC) + 1) == 0))
	{
		print_syntax_error(node_lex->text);
		ret = 1;
	}
	else
		ret = redir_without_file(lst_lexems);
	return (ret);
}

void	print_syntax_error(char *lexem)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token `", 2);
	ft_putstr_fd(lexem, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd("\n", 2);
	g_exit_status = 2;
}

int	no_word_token(t_list *lexems)
{
	t_lexem	*lex;

	while (lexems)
	{
		lex = lexems->content;
		if (ft_strncmp(lex->type, TK_WORD, ft_strlen(TK_WORD) + 1) == 0)
			return (0);
		lexems = lexems->next;
	}
	return (1);
}

int	redir_without_file(t_list *lexems)
{
	t_lexem *cur_lex;
	t_lexem	*nxt_lex;

	while (lexems)
	{
		nxt_lex = NULL;
		cur_lex = lexems->content;
		if (lexems->next)
		nxt_lex = lexems->next->content;
		
		if ((is_redir_type(cur_lex->type) && !nxt_lex)
			|| (ft_strncmp(cur_lex->text, TK_DLESS, ft_strlen(TK_DLESS) + 1) == 0
				&& !nxt_lex))
		{
			print_syntax_error("newline");
			return (1);
		}
		lexems = lexems->next;
	}
	return (0);
}