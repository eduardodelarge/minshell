/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:24:20 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/25 01:52:02 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		valid_id(char *var_name);
static int		check_varname(char *tok_txt);
static void		att_envvars(t_list **envp, t_token *token);

int	ft_export(t_list *suffix, t_list **envp, int fd)
{
	t_token	*cur_tok;
	t_list	*tmp;

	skip_redir_tokens(&suffix);
	if (!suffix)
	{
		tmp = *envp;
		while (tmp)
		{
			printf_export_no_opt(tmp->content, fd);
			tmp = tmp->next;
		}
	}
	else
	{
		while (suffix)
		{
			cur_tok = suffix->content;
			if (valid_id(cur_tok->lexem->text))
				att_envvars(envp, cur_tok);
			suffix = suffix->next;
		}		
	}
	return (0);
}

static int	valid_id(char *tok_txt)
{
	int		eq_idx;
	char	*tk_name;

	eq_idx = ft_str_find_idx(tok_txt, '=');
	if (eq_idx < 1)
		tk_name = ft_strdup(tok_txt);
	else
		tk_name = ft_substr(tok_txt, 0, eq_idx);
	if (check_varname(tk_name) == 0)
	{
		if (ft_strchr(tok_txt, '=') && eq_idx != 0)
		{
			free(tk_name);
			return (1);
		}
	}
	else
	{
		free(tk_name);
		printf_export_error(tok_txt);
		return (0);
	}
	free(tk_name);
	g_exit_status = 0;
	return (0);
}

static int	check_varname(char *tok_txt)
{
	int	i;
	int	tok_size;

	tok_size = ft_strlen(tok_txt);
	i = 0;
	while (i < tok_size)
	{
		if (i == 0)
		{
			if (!ft_isalpha(tok_txt[i]) && tok_txt[i] != '_')
				return (-1);
		}
		else
		{
			if (!ft_isalnum(tok_txt[i]) && tok_txt[i] != '_')
				return (-2);
		}
		i++;
	}
	return (0);
}

static void	att_envvars(t_list **envp, t_token *cur_tok)
{
	char	**split_tok;
	t_envp	*envvar;
	int		new_envvar;

	new_envvar = 0;
	split_tok = ft_split(cur_tok->lexem->text, '=');
	envvar = find_envvar(*envp, split_tok[0]);
	if (!envvar)
	{
		envvar = envp_init(split_tok[0]);
		new_envvar = 1;
	}
	free(envvar->value);
	if (ft_mtxlen(split_tok) > 1)
	{
		if (is_quote_apst(split_tok[1][0]))
			envvar->value = ft_rm_quotation(split_tok[1]);
		else
			envvar->value = ft_strdup(split_tok[1]);
	}
	else
		envvar->value = ft_strdup("");
	if (new_envvar)
		ft_lstadd_back(envp, ft_lstnew(envvar));
	ft_destroy_matrix(split_tok);
}
