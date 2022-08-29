/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:19:19 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/21 19:22:57 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*concat_t_envp(t_envp *var);

char	**lst2mtx_envp(t_list *records)
{
	char	**matrix;
	int		i;
	int		records_qt;

	matrix = NULL;
	records_qt = ft_lstsize(records);
	matrix = malloc(sizeof(char *) * (records_qt + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (records)
	{
		matrix[i] = concat_t_envp(records->content);
		records = records->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

static char	*concat_t_envp(t_envp *var)
{
	char	*str;
	char	*tmp;

	str = ft_strdup("");
	if (var)
	{
		tmp = str;
		str = ft_strjoin(str, var->name);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, "=");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, var->value);
		free(tmp);
	}
	return (str);
}

char	*ft_skip_space(char *str)
{
	char	*ret;

	while (ft_isspace(*str))
		str++;
	ret = str;
	return (ret);
}

char	*ft_rm_quotation(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		str_size;

	i = 0;
	j = 0;
	str_size = strlen(str);
	new_str = malloc(sizeof(char) * (str_size - 2 + 1));
	while (i < str_size)
	{
		if ((i == 0 || i == str_size - 1)
			&& (str[i] == '\"' || str[i] == '\''))
			i++;
		new_str[j++] = str[i++];
	}
	return (new_str);
}

int	cmdline_has_redir(t_cmd *cmdline)
{
	t_list	*suffix;
	t_token	*tk;

	suffix = cmdline->suffix;
	while (suffix)
	{
		tk = suffix->content;
		if (tk->file)
			return (1);
		suffix = suffix->next;
	}
	return (0);
}
