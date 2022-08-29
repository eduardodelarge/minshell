/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lex_expander.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:41:04 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 17:00:38 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_lex(t_lexem *lexem, t_list *envp);
static char	*get_exp_envvar(t_lexem *lexem, t_list *envp);
static char	*get_exp_exit_status(t_lexem *lexem);
static char	*join_parts(char *preffix, char *suffix, char *expanded);

void	ft_lex_expander(t_list **lst_lexems, t_list *envp)
{
	t_lexem	*lexem;
	t_list	*tmp;
	char	*f_lex;

	lexem = NULL;
	tmp = (*lst_lexems);
	while (tmp)
	{
		lexem = tmp->content;
		if (lexem->expansion)
		{
			f_lex = lexem->text;
			lexem->text = expand_lex(lexem, envp);
			free(f_lex);
		}
		tmp = tmp->next;
	}
}

static char	*expand_lex(t_lexem *lexem, t_list *envp)
{
	char	*ret;

	ret = NULL;
	if (ft_strncmp(lexem->expansion->type, EXP_EXIT_STATUS,
			ft_strlen(EXP_EXIT_STATUS) + 1) == 0)
		ret = get_exp_exit_status(lexem);
	else if (ft_strncmp(lexem->expansion->type, EXP_ENVVAR,
			ft_strlen(EXP_ENVVAR) + 1) == 0)
		ret = get_exp_envvar(lexem, envp);
	else
		ret = ft_strdup(lexem->text);
	return (ret);
}

static char	*get_exp_envvar(t_lexem *lexem, t_list *envp)
{
	char	*preffix;
	char	*suffix;
	char	*expanded;
	char	*ret;
	int		param_len;

	preffix = NULL;
	suffix = NULL;
	expanded = NULL;
	ret = NULL;
	param_len = ft_strlen(lexem->expansion->param);
	if (lexem->expansion->start != 0)
		preffix = ft_substr(lexem->text, 0, ft_str_find_idx(lexem->text, '$'));
	if (lexem->expansion->end != param_len - 1)
	{
		// pegar última letra do param
		// buscar ela (a partir do fim)
		suffix = ft_strrchr(lexem->text, lexem->expansion->param[ft_strlen(lexem->expansion->param) - 1]);
		suffix++;
	}
	if (suffix && !suffix[0])
	{
		// free(suffix);
		suffix = NULL;
	}
	expanded = get_envvar_value(lexem->expansion->param, envp);
	ret = join_parts(preffix, suffix, expanded);
	free(expanded);
	free(preffix);
	return (ret);
}

static char	*get_exp_exit_status(t_lexem *lexem)
{
	char	*preffix;
	char	*suffix;
	char	*expanded;
	char	*ret;
	int		param_len;

	preffix = NULL;
	suffix = NULL;
	param_len = ft_strlen(lexem->expansion->param);
	if (lexem->expansion->start != 0)
		preffix = ft_substr(lexem->text, 0, ft_str_find_idx(lexem->text, '$'));
	if (lexem->expansion->end != param_len - 1)
	{
		suffix = ft_strnstr(lexem->text, lexem->expansion->param,
				ft_strlen(lexem->text));
		suffix++;
	}
	expanded = ft_itoa(g_exit_status);
	ret = join_parts(preffix, suffix, expanded);
	free(expanded);
	free(preffix);
	return (ret);
}

static char	*join_parts(char *preffix, char *suffix, char *expanded)
{
	char	*ret;
	char	*f_tmp;

	ret = NULL;
	f_tmp = NULL;
	if (preffix)
	{
		ret = ft_strjoin(preffix, expanded);
		f_tmp = ret;
	}
	else
		ret = expanded;
	if (suffix)
		ret = ft_strjoin(ret, suffix);
	else
		ret = ft_strdup(ret);
	free(f_tmp);
	return (ret);
}
