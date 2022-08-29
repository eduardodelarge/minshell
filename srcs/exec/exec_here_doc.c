/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:38:34 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 17:39:26 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_here_doc(int fd, char *del);

int	here_doc(t_list *lst_here_doc)
{
	int		exit;
	int		pipefd[2];
	int		pid;
	t_token *here_doc;

	exit = 0;
	if (!lst_here_doc)
		return (exit);
	if (pipe(pipefd))
		pipe_error();
	// while
	here_doc = lst_here_doc->content;
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		fork_error();
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		exec_here_doc(pipefd[1], here_doc->eof->text);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	return (exit);
}

void	exec_here_doc(int fd, char *del)
{
	char	*line;
	char	*tmp;

	line = NULL;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (!line)
	{
		line = readline("> ");
		if (!line || ft_strncmp(del, line, ft_strlen(del) + 1) == 0)
			break ;
		tmp = line;
		line = ft_strjoin(line, "\n");
		ft_putstr_fd(line, fd);
		free(line);
		free(tmp);
		line = NULL;
	}
	free(line);
	close(fd);
	exit(0);
}