/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:51:17 by caeduard          #+#    #+#             */
/*   Updated: 2022/08/19 01:32:05 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "libft.h"
#include <stdbool.h>
#include <string.h>

int	g_exit_status;

// char	*lst2array(t_list *lst);

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*lst;
	t_list	*head;
	int	n1 = 1;
	int	n2 = 2;
	int	n3 = 3;
	int	n4 = 4;
	int	n5 = 5;
	char	*mtx[] = {"1", "2", "3"};

	g_exit_status = 0;
	lst = ft_lstnew(&n1);
	ft_lstadd_back(&lst, ft_lstnew(&n2));
	ft_lstadd_back(&lst, ft_lstnew(&n3));
	ft_lstadd_back(&lst, ft_lstnew(&n4));
	ft_lstadd_back(&lst, ft_lstnew(&n5));
	head = lst;
	ft_printf("clean list\n");
	while (lst)
	{
		int nbr = *(int *)lst->content;
		ft_printf("%d\n", nbr);
		lst = lst->next;
	}
	lst = head;
	// char	*nbrs = lst2array(lst);

	ft_printf("mtx to array result\n");
	ft_printf("%s\n", nbrs);
	return (0);
}

void	ft_lstrm_node_test()
{
	t_list	*lst;
	t_list	*head;
	int	n1 = 1;
	int	n2 = 2;
	int	n3 = 3;
	int	n4 = 4;
	int	n5 = 5;
	
	lst = ft_lstnew(&n1);
	ft_lstadd_back(&lst, ft_lstnew(&n2));
	ft_lstadd_back(&lst, ft_lstnew(&n3));
	ft_lstadd_back(&lst, ft_lstnew(&n4));
	ft_lstadd_back(&lst, ft_lstnew(&n5));
	head = lst;
	ft_printf("clean list\n");
	while (lst)
	{
		int nbr = *(int *)lst->content;
		ft_printf("%d\n", nbr);
		lst = lst->next;
	}
	lst = head;
	ft_lstrm_node(&lst, head->next->next->next->next);

	ft_printf("one removed\n");
	while (lst)
	{
		int nbr = *(int *)lst->content;
		ft_printf("%d\n", nbr);
		lst = lst->next;
	}
}
