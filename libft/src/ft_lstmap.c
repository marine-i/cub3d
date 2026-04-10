/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:25:30 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:13 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*tmp_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp_content = f(lst->content);
		new_node = ft_lstnew(tmp_content);
		if (!new_node)
		{
			del(tmp_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*#include <stdio.h>
int main(void)
{
	t_list	*original = NULL;
	t_list	*modifier = NULL;
	t_list	*tmp;

	ft_lstadd_back(&original, ft_lstnew("coucou"));
	ft_lstadd_back(&original, ft_lstnew("marine"));
	ft_lstadd_back(&original, ft_lstnew("tichou"));

	printf("Liste avant modif:\n");
	tmp = original;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	modifier = ft_lstmap(original, print_upper, del);
	if (!modifier)
		printf("\nerreur:\n");

	printf("\nListe apres modif:\n");
	while (modifier)
	{
		printf("%s\n", (char *)modifier->content);
		modifier = modifier->next;
	}
}

void	*print_upper(void *content)
{
	int	i;
	char *str = (char *)content;
	char *cpy = ft_strdup(str);
	i = 0;
	if (!cpy)
		return (NULL);
	while (cpy[i])
	{
		if (cpy[i] >= 'a' && cpy[i] <= 'z')
			cpy[i] -= 32;
		i++;
	}
	return (cpy);
}

void	del(void *content)
{
	//printf("Suppression de : %s\n", (char *)content);
	free(content);
}*/