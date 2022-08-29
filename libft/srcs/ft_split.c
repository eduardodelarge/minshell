/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:10:54 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/05 14:33:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int				ft_wc(char const *str, char c);
static char				**free_tab(char **tab, size_t size);
static const char		*skip_unwc(char const *ptr, int c);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nstrs;
	int		i;
	int		strlen;

	if (!s)
		return (0);
	nstrs = ft_wc(s, c);
	tab = malloc(sizeof(char *) * (nstrs + 1));
	if (!tab)
		return (0);
	i = -1;
	while (++i < nstrs)
	{
		s = skip_unwc(s, c);
		strlen = 0;
		while (s[strlen] && s[strlen] != c)
			strlen++;
		tab[i] = ft_substr(s, 0, strlen);
		if (!tab)
			return (free_tab(tab, i));
		s += strlen + 1;
	}
	tab[nstrs] = 0;
	return (tab);
}

static int	ft_wc(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (count);
}

static char	**free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (0);
}

static const char	*skip_unwc(char const *ptr, int c)
{
	while (*ptr && *ptr == c)
		ptr++;
	return (ptr);
}
