/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:47:37 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/25 01:00:22 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	if (c == '>' || c == '<')
		return (1);
	if (c == '&' || c == '|')
		return (1);
	return (0);
}

int	is_quote_apst(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	is_redir_type(char *type)
{
	if (ft_strncmp(type, TK_GREAT, ft_strlen(TK_GREAT)) == 0
		|| ft_strncmp(type, TK_DGREAT, ft_strlen(TK_DGREAT)) == 0
		|| ft_strncmp(type, TK_LESS, ft_strlen(TK_LESS)) == 0)
		return (1);
	return (0);
}

int	is_expansion(char *text)
{
	int	dsign_idx;
	int	txt_len;

	txt_len = ft_strlen(text);
	dsign_idx = ft_str_find_idx(text, '$');
	if (txt_len > dsign_idx + 1
		&& (ft_isalpha(text[dsign_idx + 1]) || text[dsign_idx + 1] == '?'))
	{
		if ((text[0] != '\'' && dsign_idx != -1))
			return (1);
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, ECHO, ft_strlen(ECHO) + 1) == 0)
		return (1);
	else if (ft_strncmp(cmd, CD, ft_strlen(CD) + 1) == 0)
		return (1);
	if (ft_strncmp(cmd, PWD, ft_strlen(PWD) + 1) == 0)
		return (1);
	else if (ft_strncmp(cmd, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		return (1);
	else if (ft_strncmp(cmd, UNSET, ft_strlen(UNSET) + 1) == 0)
		return (1);
	else if (ft_strncmp(cmd, ENV, ft_strlen(ENV) + 1) == 0)
		return (1);
	else if (ft_strncmp(cmd, EXIT, ft_strlen(EXIT) + 1) == 0)
		return (1);
	return (0);
}
