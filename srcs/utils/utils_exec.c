/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:17:37 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/19 17:36:21 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*find_path(char *cmd, char *path_value)
{
	int		i;
	char	**paths;
	char	*abs_cmd;
	char	*tmp;

	paths = ft_split(path_value, ':');
	i = 0;
	while (paths[i])
	{
		abs_cmd = ft_strjoin(paths[i], "/");
		tmp = abs_cmd;
		abs_cmd = ft_strjoin(abs_cmd, cmd);
		free(tmp);
		if (access(abs_cmd, X_OK) == 0)
		{
			ft_destroy_matrix(paths);
			return (abs_cmd);
		}
		free(abs_cmd);
		i++;
	}
	ft_destroy_matrix(paths);
	return (NULL);
}

char	*get_path(char *cmd, t_list *envp)
{
	char	*abs_path;
	t_envp	*envvar;

	abs_path = NULL;
	while (envp)
	{
		envvar = envp->content;
		if (ft_strncmp(envvar->name, "PATH", ft_strlen("PATH") + 1) == 0)
		{
			abs_path = find_path(cmd, envvar->value);
			if (abs_path)
				return (abs_path);
		}
		envp = envp->next;
	}
	return (abs_path);
}
