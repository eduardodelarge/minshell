/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:52:57 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/28 03:29:25 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_operator(const char *str, int index);
static int	quotation_check(char *input, int *att, int *quot, int *apst);

int	get_token_size(char *input)
{
	int	i;
	int	inside_tk;
	int	quot;
	int	apst;
	int	att;

	i = 0;
	inside_tk = 0;
	apst = 1;
	quot = 1;
	input = ft_skip_space(input);
	att = 0;
	while (input[i])
	{
		if ((apst && quot && !att) && !is_quote_apst(input[i])
			&& ((i == 0 || ft_isspace(input[i - 1]) || check_operator(input, i)
					|| is_quote_apst(input[i - 1]) || ft_isspace(input[i]))))
			inside_tk = !inside_tk;
		if (quotation_check(input + i, &att, &quot, &apst))
			inside_tk = !inside_tk;
		if (!inside_tk && !att)
			return (i);
		i++;
	}
	return (i);
}

static int	check_operator(const char *str, int index)
{
	if ((is_operator(str[index]) && !is_operator(str[index - 1]))
		|| (!is_operator(str[index]) && is_operator(str[index - 1])))
		return (1);
	return (0);
}

static int	quotation_check(char *input, int *att, int *quot, int *apst)
{
	if (input[0] == '=' || ((*att) && (ft_isspace(input[0]) && *quot && *apst)))
		(*att) = !(*att);
	if (input[0] == '\'')
	{
		if ((*quot))
		{
			(*apst) = !(*apst);
			if (!((*quot) && (*apst)))
				return (1);
		}
	}
	if (input[0] == '\"')
	{
		if ((*apst))
		{
			(*quot) = !(*quot);
			if (!((*quot) && (*apst)))
				return (1);
		}
	}
	return (0);
}
