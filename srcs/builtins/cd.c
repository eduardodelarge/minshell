/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:14:38 by caeduard          #+#    #+#             */
/*   Updated: 2022/08/28 06:26:41 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*param_expansion(char *tok_txt, t_list *envp);
void	chdir_op(char *path, t_list **envp);
void	chdir_op_no_param(t_list *envp);

int	ft_cd(t_list *suffix, t_list **envp)
{
	char	*path;
	t_token	*token;

	g_exit_status = 0;
	skip_redir_tokens(&suffix);
	if (suffix)
	{
		if (ft_lstsize(suffix) > 1)
			printf_cd_error();
		else
		{
			token = suffix->content;
			path = param_expansion(token->lexem->text, *envp);
			chdir_op(path, envp);
			free(path);
		}
	}
	else
		chdir_op_no_param(*envp);
	return (0);
}

char	*param_expansion(char *tok_txt, t_list *envp)
{
	t_envp	*home;
	char	*path;
	char	*tmp;

	path = NULL;
	if ((ft_str_find_idx(tok_txt, '~') == 0 && ft_strlen(tok_txt) == 1)
		|| ft_strnstr(tok_txt, "~/", 2))
	{
		home = find_envvar(envp, "HOME");
		if (!home)
			return (NULL);
		if (ft_strncmp(tok_txt, "~", ft_strlen("~") + 1) == 0)
			path = ft_strdup(home->value);
		else if (ft_strnstr(tok_txt, "~/", 2))
		{
			path = ft_strjoin("/", tok_txt + 2);
			tmp = path;
			path = ft_strjoin(home->value, tmp);
			free(tmp);
		}
	}
	else
		path = ft_strdup(tok_txt);
	return (path);
}

void	chdir_op(char *path, t_list **envp)
{
	DIR		*dir;
	char	*msg;

	dir = opendir(path);
	if (!dir)
	{
		msg = ft_strjoin("minishell: cd: ", path);
		g_exit_status = 1;
		perror(msg);
		closedir(dir);
		free(msg);
	}
	else
	{
		att_oldpwd(envp);
		chdir(path);
		att_pwd(envp);
		closedir(dir);
	}
}

void	chdir_op_no_param(t_list *envp)
{
	t_envp	*home;
	DIR		*dir;

	home = find_envvar(envp, "HOME");
	if (home)
	{
		dir = opendir(home->value);
		if (!dir)
		{
			g_exit_status = 1;
			perror("minishell: cd: ");
		}
		else
			chdir(home->value);
		closedir(dir);
	}
	else
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g_exit_status = 1;
	}
}
