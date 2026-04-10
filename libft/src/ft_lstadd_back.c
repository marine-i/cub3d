/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:48:16 by maiguna           #+#    #+#             */
/*   Updated: 2025/08/01 18:35:04 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*#include <stdio.h>
int	main(void)
{
last = *lst;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
	t_list	*test = NULL;

	ft_lstadd_front(&test, ft_lstnew("test1"));
	ft_lstadd_front(&test, ft_lstnew("test2"));
	ft_lstadd_front(&test, ft_lstnew("test3"));

	//printf("%d\n", ft_lstsize(test));

	ft_lstadd_back(&test, ft_lstnew("1"));
	ft_lstadd_back(&test, ft_lstnew("2"));
	ft_lstadd_back(&test, ft_lstnew("3"));

	//printf("%s\n", (char *)ft_lstlast(test)->content);

	while (test)
	{
		printf("%s\n", (char *)test->content);
		test = test->next;
	}

	while (test)
	{
		printf("%s\n", (char *)test->content);
		test = test->next;
	}
}*/