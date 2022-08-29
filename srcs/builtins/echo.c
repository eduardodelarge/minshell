/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:05:03 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 01:59:27 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	put_into_fd(t_token *token, t_list *param, int fd, char **r_input);
static int	skip_echo_flag(t_list **param, t_token *token);

int	ft_echo(t_list *param, int fd, char *raw_input)
{
	t_token	*token;
	t_list	*head;
	int		bl_flag;

	bl_flag = 0;
	head = param;
	while (param)
	{
		token = param->content;
		if (!is_redir_type(token->lexem->type))
		{
			if (head == param)
				bl_flag = skip_echo_flag(&param, token);
			if (!param)
				break ;
			token = param->content;
			put_into_fd(token, param, fd, &raw_input);
		}
		param = param->next;
	}
	if (!bl_flag)
		ft_putstr_fd("\n", fd);
	g_exit_status = 0;
	return (0);
}

static void	put_into_fd(t_token *token, t_list *param, int fd, char **r_input)
{
	int	i;

	i = 0;
	ft_putstr_fd(token->lexem->text, fd);
	param = param->next;
	*r_input = ft_strnstr(*r_input, token->lexem->text, ft_strlen(*r_input));
	*r_input = *r_input + ft_strlen(token->lexem->text);

	if (param)
	{
		while (token->lexem->text[0] && (*r_input)[i])
		{
			if ((*r_input)[i] == ' ')
			{
				ft_putstr_fd(" ", fd);
				break ;
			}
			i++;
		}
	}
}

static int	skip_echo_flag(t_list **param, t_token *token)
{
	int	bl_flag;

	bl_flag = 0;
	if (!param)
		return (bl_flag);
	while (*param && token && ft_strncmp(token->lexem->text, "-n", 3) == 0)
	{
		bl_flag = 1;
		*param = (*param)->next;
		if (*param)
			token = (*param)->content;
	}
	return (bl_flag);
}
