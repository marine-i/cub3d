/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:06:18 by maiguna           #+#    #+#             */
/*   Updated: 2025/08/01 18:35:04 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void print_upper(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(strdup("bonjour")));
	ft_lstadd_back(&list, ft_lstnew(strdup("marine")));
	ft_lstadd_back(&list, ft_lstnew(strdup("ecole")));

	printf("Avant ft_lstiter :\n");
	print_list(list);

	ft_lstiter(list, print_upper);

	printf("Après ft_lstiter :\n");
	print_list(list);

}*/