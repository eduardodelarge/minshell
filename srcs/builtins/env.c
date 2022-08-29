/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:12:43 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 11:17:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_list *envp, int fd)
{
	t_envp	*envvar;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		while (envp)
		{
			if (envp->content)
			{
				envvar = envp->content;
				ft_putstr_fd(envvar->name, fd);
				ft_putstr_fd("=", fd);
				ft_putstr_fd(envvar->value, fd);
				ft_putstr_fd("\n", fd);
			}
			envp = envp->next;
		}
		ft_lstclear(&envp, free_t_envp);
		exit (0);
	}
	g_exit_status = 0;
	return (0);
}
