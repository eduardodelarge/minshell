/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:53:33 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/24 12:08:25 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"

int	g_exit_status;

int	main(int argc, char *argv[], char *envp[])
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd))
		return (2);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		if (execlp("cat", "minishell", NULL))
			exit (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		// close(pipefd[1]);
		if (execlp("grep", "grep", "a", NULL))
			exit (EXIT_FAILURE);
	}
	
	close(pipefd[0]);
	close(pipefd[1]);
	ft_printf("ok\n");
	waitpid(-1, NULL, 0);
	return (0);
}