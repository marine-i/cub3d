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

void	free_path_textures(t_data *data)
{
	if (data->textures.no_path)
		free(data->textures.no_path);
	if (data->textures.ea_path)
		free(data->textures.ea_path);
	if (data->textures.so_path)
		free(data->textures.so_path);
	if (data->textures.we_path)
		free(data->textures.we_path);
}


void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->map.tmp_map)
		data_clear(&data->map.tmp_map);
	if (data->map.map)
		free_split(data->map.map);
	free_path_textures(data);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
