#include "main.h"

void	get_player(t_data *data, int i, int j, char *tmp_line)
{
	if (tmp_line[j] == 'N') // dup for S W E
	{
		data->player.pos_x = j;
		data->player.pos_y = i;
		data->map.pos_x = j; // a supp?
		data->map.pos_y = i; // a supp?
		// data->player.dir_x = 'N'; // a voir 
		// data->player.dir_y = 'N'; // a voir 
	}
}

int	handle_fill_map(int i, t_list *tmp, t_data *data)
{
	int		j;
	char	*tmp_line;

	// if !tmp
	j = 0;
	tmp_line = (char *)tmp->content;
	while (tmp_line[j])
	{
		get_player(data, i, j, tmp_line);
		if (tmp_line[j] == ' ')
			data->map.map[i][j] = '1';
		else
			data->map.map[i][j] = tmp_line[j];
		j++;
	}
	while (j < data->map.width)
	{
		data->map.map[i][j] = 'X';
		j++;
	}
	data->map.map[i][j] = '\0';
	return (SUCCESS);
}

int	fill_map(t_data *data)
{
	int		i;
	t_list	*tmp;

	i = 0;
	data->map.map = malloc(sizeof(char *) * (data->map.nb_line_map + 1));
	if (!data->map.map)
		return (print_error(ERR_MALLOC), FAILURE);
	tmp = data->map.tmp_map;
	while (i < data->map.nb_line_map && tmp)
	{
		data->map.map[i] = malloc(sizeof (char *) * (data->map.width) + 1);
		// data->map.map[i] = malloc(sizeof (char *) * (ft_strlen(tmp->content) + 1));
		if (!data->map.map[i])
			return (ft_free(data->map.map, i), print_error(ERR_MALLOC), FAILURE);
		if (handle_fill_map(i, tmp, data) == FAILURE)
			return (ft_free(data->map.map, i), print_error("ca va pas"), FAILURE); // a changer
		i++;
		tmp = tmp->next;
	}
	data->map.map[data->map.nb_line_map] = NULL;
	return (SUCCESS);
}
