#include "main.h"

void	data_clear(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		if (tmp->content)
			free(tmp->content);
		if (tmp)
			free(tmp);
	}
	*lst = NULL;
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->map.tmp_map)
		data_clear(&data->map.tmp_map);
}


void	*ft_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}
