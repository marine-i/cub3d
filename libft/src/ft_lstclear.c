/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:05:52 by maiguna           #+#    #+#             */
/*   Updated: 2025/12/05 08:18:43 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

// #include <stdio.h>

// void del(void *content)
// {
// 	printf("Suppression de : %s\n", (char *)content);
// 	free(content);
// }

// void print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("node : %s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int main(void)
// {
// 	t_list *a = malloc(sizeof(t_list));
// 	t_list *b = malloc(sizeof(t_list));
// 	t_list *c = malloc(sizeof(t_list));

// 	a->content = strdup("Bonjour");
// 	b->content = strdup("Marine");
// 	c->content = strdup("42");

// 	a->next = b;
// 	b->next = c;
// 	c->next = NULL;

// 	t_list *list = a;

// 	printf("Liste avant:\n");
// 	print_list(list);

// 	ft_lstclear(&list, del);

// 	printf("\nListe apres:\n");
// 	print_list(list);

// }
