/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:09:42 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/07 21:23:41 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nlen(int n);
static char	*ft_alloc_nstr(int n, int nlen);
static char	*ft_intmin(void);

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	int		negat;

	negat = n < 0;
	if (n == -2147483648)
		return (ft_intmin());
	nlen = ft_nlen(n);
	str = ft_alloc_nstr(n, nlen);
	if (!str)
		return (0);
	if (negat)
	{
		n = -n;
		str[0] = '-';
		nlen++;
	}
	while (n)
	{
		str[--nlen] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static int	ft_nlen(int n)
{
	int	len;

	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_alloc_nstr(int n, int nlen)
{
	char	*ptr;

	if (n < 0)
		ptr = (char *)malloc(nlen + 1 + 1);
	else
		ptr = (char *)malloc(nlen + 1);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	if (n < 0)
		ptr[nlen + 1] = '\0';
	else
		ptr[nlen] = '\0';
	return (ptr);
}

static char	*ft_intmin(void)
{
	char	*str;

	str = malloc(11 + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}
