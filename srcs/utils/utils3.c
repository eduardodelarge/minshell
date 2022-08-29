/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:12:54 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 05:02:36 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	param_count_redir(t_list *suffix);
static void	put_tokens_to_mtx(t_cmd *cmdtable, char ***matrix);

char	**cmdline2mtx_normal(t_cmd *cmdtable)
{
	char	**matrix;
	int		i;
	int		list_size;
	t_list	*tmp;
	t_token	*token;

	matrix = NULL;
	list_size = ft_lstsize(cmdtable->suffix) + 1;
	matrix = malloc(sizeof(char *) * (list_size + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	matrix[i] = ft_strdup(cmdtable->name->lexem->text);
	tmp = cmdtable->suffix;
	i++;
	while (tmp)
	{
		token = tmp->content;
		matrix[i] = ft_strdup(token->lexem->text);
		tmp = tmp->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**cmdline2mtx_redir(t_cmd *cmdtable)
{
	char	**matrix;
	int		list_size;

	matrix = NULL;
	list_size = param_count_redir(cmdtable->suffix) + 1;
	matrix = malloc(sizeof(char *) * (list_size + 1));
	if (!matrix)
		return (NULL);
	put_tokens_to_mtx(cmdtable, &matrix);
	return (matrix);
}

static int	param_count_redir(t_list *suffix)
{
	int		tk_qtd;
	t_token	*tk;

	tk_qtd = 0;
	while (suffix)
	{
		tk = suffix->content;
		if (tk && !tk->file)
			tk_qtd++;
		suffix = suffix->next;
	}
	return (tk_qtd);
}

void	skip_redir_tokens(t_list **suffix)
{
	t_token	*cur_tok;

	while ((*suffix))
	{
		cur_tok = (*suffix)->content;
		if (!is_redir_type(cur_tok->lexem->type))
			break ;
		(*suffix) = (*suffix)->next;
	}
}

static void	put_tokens_to_mtx(t_cmd *cmdtable, char ***matrix)
{
	t_list	*tmp;
	int		i;
	t_token	*token;

	(*matrix)[0] = ft_strdup(cmdtable->name->lexem->text);
	tmp = cmdtable->suffix;
	i = 1;
	while (tmp)
	{
		token = tmp->content;
		if (token && !token->file)
		{
			(*matrix)[i] = ft_strdup(token->lexem->text);
			i++;
		}
		tmp = tmp->next;
	}
	(*matrix)[i] = NULL;
}
