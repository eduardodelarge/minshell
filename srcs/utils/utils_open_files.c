/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_open_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:03:43 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/23 00:40:03 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	file_open_type(char *file, char *tk_type, t_redir **fds);
static void	open_outfile(char *file, char *tk_type, t_redir **fds);

t_redir	*open_files(char *file, char *tk_type)
{
	t_redir	*fds;

	fds = redir_init();
	if (ft_strncmp(tk_type, TK_GREAT, ft_strlen(TK_GREAT) + 1) == 0
		|| ft_strncmp(tk_type, TK_DGREAT, ft_strlen(TK_DGREAT) + 1) == 0)
	{
		open_outfile(file, tk_type, &fds);
	}
	else if (ft_strncmp(tk_type, TK_LESS, ft_strlen(TK_LESS) + 1) == 0)
	{
		if (access(file, F_OK) != 0)
			fds->fdin = printf_openfile_error(file, ERR_FNOEXST);
		else
		{
			if (access(file, R_OK) != 0)
				fds->fdin = printf_openfile_error(file, ERR_NOPERM);
			else
				file_open_type(file, tk_type, &fds);
		}
	}
	return (fds);
}

t_redir	*there_is_redir(t_list *suffix)
{
	char	*file;
	t_token	*tk;
	t_redir	*fds;

	fds = NULL;
	while (suffix)
	{
		if (fds && (fds->fdin < 0 || fds->fdout < 0))
			break ;
		tk = suffix->content;
		if (tk->file)
		{
			file = tk->file->text;
			if (fds)
				free(fds);
			fds = open_files(file, tk->lexem->type);
		}
		suffix = suffix->next;
	}
	return (fds);
}

static void	file_open_type(char *file, char *tk_type, t_redir **fds)
{
	if (*fds)
	{
		if (ft_strncmp(tk_type, TK_GREAT, ft_strlen(TK_GREAT) + 1) == 0)
			(*fds)->fdout = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		else if (ft_strncmp(tk_type, TK_DGREAT, ft_strlen(TK_DGREAT) + 1) == 0)
			(*fds)->fdout = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
		if (ft_strncmp(tk_type, TK_LESS, ft_strlen(TK_LESS) + 1) == 0)
			(*fds)->fdin = open(file, O_RDONLY);
	}
}

static void	open_outfile(char *file, char *tk_type, t_redir **fds)
{
	if (access(file, F_OK) != 0)
	{
		file_open_type(file, tk_type, fds);
		if ((*fds)->fdin < 0 || (*fds)->fdout < 0)
			printf_openfile_error(file, ERR_FNOEXST);
	}
	else
	{
		if (access(file, W_OK) == 0)
			file_open_type(file, tk_type, fds);
		else
			(*fds)->fdout = printf_openfile_error(file, ERR_NOPERM);
	}
}
