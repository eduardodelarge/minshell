/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:21:31 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/19 01:35:54 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*init_envp_list(char *envp[])
{
	t_list	*envp_list;
	t_envp	*envvar;
	char	**envvar_split;
	int		i;

	envp_list = NULL;
	envvar = NULL;
	if (envp)
	{
		i = 0;
		while (envp[i])
		{
			envvar = (t_envp *)malloc(sizeof(t_envp));
			envvar_split = ft_split_idx(envp[i], ft_str_find_idx(envp[i], '='));
			envvar->name = ft_strdup(envvar_split[0]);
			envvar->value = ft_strdup(envvar_split[1]);
			if (!envp_list)
				envp_list = ft_lstnew(envvar);
			else
				ft_lstadd_back(&envp_list, ft_lstnew(envvar));
			ft_destroy_matrix(envvar_split);
			i++;
		}
	}
	return (envp_list);
}
