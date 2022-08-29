/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:28:59 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 01:40:09 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printf_export_no_opt(t_envp *envvar, int fd)
{
	ft_putstr_fd("declare -x", fd);
	ft_putstr_fd(envvar->name, fd);
	ft_putstr_fd("=", fd);
	ft_putstr_fd(envvar->value, fd);
	ft_putstr_fd("\n", fd);
}

void	close_fds(int fdin, int fdout)
{
	if (fdout > 2)
		close(fdout);
	if (fdin > 2)
		close(fdin);
}

void	rm_quote_from_lexems(t_list **lst_lexems)
{
	t_list	*tmp;
	t_lexem	*lex;
	char	*f_lex;

	tmp = *lst_lexems;
	while (tmp)
	{
		lex = tmp->content;
		if (lex->text && (lex->text[0] == '\'' || lex->text[0] == '\"'))
		{
			f_lex = lex->text;
			if (ft_strncmp(lex->text, "\"\"", ft_strlen("\"\"") + 1) == 0
				|| ft_strncmp(lex->text, "\'\'", ft_strlen("\'\'") + 1) == 0)
				lex->text = ft_strdup("");
			else
				lex->text = ft_rm_quotation(lex->text);
			free(f_lex);
		}
		tmp = tmp->next;
	}
}

char	*rm_break_line(char **input)
{
	int		l_size;
	char	*ret;

	ret = *input;
	if (input && *input)
	{
		l_size = ft_strlen(*input);
		ret[l_size - 1] = '\0';
	}
	return (ret);
}