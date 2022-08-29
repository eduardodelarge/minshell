/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:56:41 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 03:53:55 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input_line(char *prompt_str);
void	free_input(char	**input, t_cmd **cmdtable);
void	shutdown_env(t_list	**envp);
void	arg_check(int argc, char *argv[]);

int		g_exit_status = 0;

int	main(int argc, char *argv[], char *env[])
{
	char	*cmdline;
	t_cmd	*cmd_table;
	t_list	*envp;
	int		exit;

	arg_check(argc, argv);
	exit = 0;
	envp = init_envp_list(env);
	while (1)
	{
		setup_signals();
		cmdline = get_input_line(PROMPT_STR);
		if (cmdline == NULL)
			break ;
		if (strncmp(cmdline, "", 1) != 0)
			add_history(cmdline);
		cmd_table = get_cmdtable(cmdline, envp);
		if (cmd_table)
			exit = exec_cmdline(cmd_table, &envp);
		free_input(&cmdline, &cmd_table);
		if (exit)
			break ;
	}
	shutdown_env(&envp);
	return (g_exit_status);
}

char	*get_input_line(char *prompt_str)
{
	char	*input;

	input = readline(prompt_str);
	if (input == NULL)
	{
		ft_printf("exit\n");
		return (NULL);
	}
	else
		return (input);
}

void	free_input(char	**input, t_cmd **cmdtable)
{
	if (*cmdtable)
		free_t_cmd(*cmdtable);
	cmdtable = NULL;
	free(*input);
}

void	shutdown_env(t_list	**envp)
{
	rl_clear_history();
	clear_history();
	ft_lstclear(envp, free_t_envp);
}

void	arg_check(int argc, char *argv[])
{
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("No argument required\n", 2);
		exit(EXIT_FAILURE);
	}
}
