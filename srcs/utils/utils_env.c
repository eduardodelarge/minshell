/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:04:27 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 15:14:46 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	att_oldpwd(t_list **envp)
{
	t_token	*tk_oldpwd;
	t_lexem	*lex_oldpwd;
	t_list	*node;
	char	buf[4096];
	char	*join;

	join = ft_strjoin("OLDPWD=", getcwd(buf, 4096));
	lex_oldpwd = lexem_init(join);
	tk_oldpwd = token_init(lex_oldpwd);
	node = ft_lstnew(tk_oldpwd);
	ft_export(node, envp, 1);
	ft_lstdelone(node, free_t_token);
	free(join);
}

void	att_pwd(t_list **envp)
{
	t_token	*tk_oldpwd;
	t_lexem	*lex_oldpwd;
	t_list	*node;
	char	buf[4096];
	char	*join;

	join = ft_strjoin("PWD=", getcwd(buf, 4096));
	lex_oldpwd = lexem_init(join);
	tk_oldpwd = token_init(lex_oldpwd);
	node = ft_lstnew(tk_oldpwd);
	ft_export(node, envp, 1);
	ft_lstdelone(node, free_t_token);
	free(join);
}

char	*get_envvar_value(char *param, t_list *envp)
{
	int		len;
	char	*var;
	t_envp	*envvar;

	len = ft_strlen(param);
	while (envp)
	{
		envvar = envp->content;
		if (ft_strncmp(envvar->name, param, len + 1) == 0)
		{
			var = ft_strdup(envvar->value);
			return (var);
		}
		envp = envp->next;
	}
	return (ft_strdup(""));
}

t_envp	*find_envvar(t_list *envp, char *varname)
{
	t_envp	*cur_envvar;

	while (envp)
	{
		cur_envvar = envp->content;
		if (ft_strncmp(cur_envvar->name, varname, ft_strlen(varname) + 1) == 0)
			return (cur_envvar);
		envp = envp->next;
	}
	return (NULL);
}
