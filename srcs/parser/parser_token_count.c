/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:25:39 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/22 04:57:06 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_operator(char *str, int index);
static int	quotation_check(char *input, int *quot, int *apst, int *att);

int	token_count(char *input)
{
	int	i;
	int	count;
	int	quot;
	int	apst;
	int	att;

	i = 0;
	count = 0;
	apst = 1;
	quot = 1;
	att = 0;
	while (input[i])
	{
		if ((apst && quot && !att) && !is_quote_apst(input[i])
			&& ((!ft_isspace(input[i])) && (i == 0 || ft_isspace(input[i - 1])
					|| check_operator(input, i)
					|| is_quote_apst(input[i - 1]))))
			count++;
		if (quotation_check(input + i, &quot, &apst, &att))
			count++;
		i++;
	}
	if (!(apst && quot))
		return (-1);
	return (count);
}

static int	check_operator(char *str, int index)
{
	if ((is_operator(str[index]) && !is_operator(str[index - 1]))
		|| (!is_operator(str[index]) && is_operator(str[index - 1])))
		return (1);
	return (0);
}

static int	quotation_check(char *input, int *quot, int *apst, int *att)
{
	if (input[0] == '=' || ((*att) && ft_isspace(input[0])))
		(*att) = !(*att);
	if (input[0] == '\'')
	{
		if ((*quot))
		{
			(*apst) = !(*apst);
			if (!((*quot) && (*apst)) && !(*att))
				return (1);
		}
	}
	if (input[0] == '\"')
	{
		if ((*apst))
		{
			(*quot) = !(*quot);
			if (!((*quot) && (*apst)) && !(*att))
				return (1);
		}
	}
	return (0);
}
