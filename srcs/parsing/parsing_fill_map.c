#include "main.h"

int	fill_map(t_data *data)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	*tmp_line;

	i = 0;
	data->map.map = malloc(sizeof(char *) * (data->map.nb_line_map + 1));
	if (!data->map.map)
		return (print_error(ERR_MALLOC), FAILURE);
	tmp = data->map.tmp_map;
	while (i < data->map.nb_line_map && tmp)
	{
		j = 0;
		tmp_line = (char *)tmp->content;
		data->map.map[i] = malloc(sizeof (char) * (data->map.width) + 1);
		if (!data->map.map[i])
			return (ft_free(data->map.map, i), print_error(ERR_MALLOC), FAILURE);
		while (tmp_line[j])
		{
			if (tmp_line[j] == 'N')
			{
				data->player.pos_x = j;
				data->player.pos_y = i;
				if (tmp_line[j] == 'N')
					data->player.dir_x = 'N'; // a voir 
				printf("le joueur est en x %d y %d\n", data->player.pos_x , data->player.pos_y);
			}
			data->map.map[i][j] = tmp_line[j];
			j++;
		}
		while (j < data->map.width)
		{
			data->map.map[i][j] = ' ';
			j++;
		}
		data->map.map[i][j] = '\0';
		i++;
		tmp = tmp->next;
	}
	data->map.map[data->map.nb_line_map] = NULL;
	return (SUCCESS);
}
