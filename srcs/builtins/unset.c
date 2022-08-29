/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:06:20 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 04:06:50 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	invalid_varname_unset(char *tok_txt);
static void	rm_envvar(t_list **envp, char *param);

int	ft_unset(t_list *suffix, t_list **envp)
{
	t_token	*token;
	char	*param_txt;

	while (suffix)
	{
		if (suffix->content)
		{
			token = suffix->content;
			param_txt = token->lexem->text;
			if (ft_strrchr(param_txt, '=')
				|| invalid_varname_unset(param_txt))
				printf_unset_error(param_txt);
			else
				rm_envvar(envp, param_txt);
		}
		suffix = suffix->next;
	}
	return (g_exit_status);
}

static int	invalid_varname_unset(char *tok_txt)
{
	int	i;
	int	tok_len;

	i = 0;
	tok_len = ft_strlen(tok_txt);
	while (i < tok_len)
	{
		if (i == 0)
		{
			if (!ft_isalpha(tok_txt[i]) && tok_txt[i] != '_')
				return (1);
		}
		else
		{
			if (!ft_isalnum(tok_txt[i]) && tok_txt[i] != '_')
				return (2);
		}
		i++;
	}
	return (0);
}

static void	rm_envvar(t_list **envp, char *param)
{
	t_list	*tmp;
	t_envp	*envvar;

	tmp = *envp;
	while (tmp)
	{
		if (tmp->content)
		{
			envvar = tmp->content;
			if (ft_strncmp(envvar->name, param, ft_strlen(param)) == 0)
			{
				ft_lstrm_node(envp, tmp);
				free_t_envp(tmp->content);
				free(tmp);
				break ;
			}
		}
		tmp = tmp->next;
	}
}
