#include "main.h"

//  check valid map

int	check_elements(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (CONTINUE);
	if (ft_strncmp(&str[i], "NO ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.no_path));
	if (ft_strncmp(&str[i], "SO ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.so_path));
	if (ft_strncmp(&str[i], "WE ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.we_path));
	if (ft_strncmp(&str[i], "EA ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.ea_path));
	if (ft_strncmp(&str[i], "F ", 2) == 0)
		return (parse_color(&str[i + 2], &data->textures.floor_color));
	if (ft_strncmp(&str[i], "C ", 2) == 0)
		return (parse_color(&str[i + 2], &data->textures.ceiling_color));
	return (MAP);
}

// element valide : 0 n s e w " "

int	check_map_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n') // a voir
			str[i] = '\0';
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			data->map.check_element++;
			if (data->map.check_element > 1)
				return (print_error(ERR_MAP_PLAYERS), FAILURE);
		}
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != '\0' && str[i] != ' ' && str[i] != '	') // tab?
			return(print_error(ERR_MAP_INVALID), FAILURE); // a supp
		i++;
	}
	return (SUCCESS);
}

// parcourir ligne bool si 1 , si 0 ou  et bool = 0 erreur
//si != ' '  ou '	' ou 1

int	check_ret_elements(t_data *data, int ret, char *line)
{
	if (ret == FAILURE)
		return (FAILURE);
	else if (ret == SUCCESS)
		data->textures.count_elements++;
	else if (ret == MAP)
	{
		if (data->textures.count_elements < 6)
			return (print_error(ERR_FILE_CONF), FAILURE);
		data->map.nb_line_map++;
		check_map_line(line, data);
		ft_lstadd_back(&data->map.tmp_map, ft_lstnew(ft_strdup(line)));
	}
	else if (ret == CONTINUE && data->map.nb_line_map > 0) // si on a deja commencé à lire la map et qu'on tombe sur une ligne vide ou que c'est la fin du fichier
		data->map.map_interrupted = 1;
	return (SUCCESS);
}

int	check_error_file(t_data *data, int ret)
{
	if (ret == MAP && data->map.map_interrupted == 1)
		return (print_error(ERR_MAP_INVALID), FAILURE);
	if (data->textures.count_elements < 6)
		return (print_error(ERR_FILE_ELEM), FAILURE);
	if (data->map.nb_line_map == 0)
		return (print_error(ERR_NO_MAP), FAILURE);
	if (data->map.map == NULL && data->textures.count_elements < 6)
		return (print_error(ERR_FILE_EMPTY), FAILURE);
	if (data->map.check_element == 0)
		return (print_error(ERR_MAP_NO_PLAYERS), FAILURE);
	return (SUCCESS);
}

int	read_file_content(int fd, t_data *data)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	if (!line)
		return (print_error(ERR_FILE_EMPTY), FAILURE);
	while (line)
	{
		ret = check_elements(line, data);
		if (check_ret_elements(data, ret, line) == FAILURE)
			return (free(line), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	if (check_error_file(data, ret) == FAILURE)
		return (free(line), FAILURE);
	free(line);
	return (SUCCESS);
}

	// while (data->map.tmp_map)
	// {
	// 	printf("%s", (char *)data->map.tmp_map->content);
	// 	data->map.tmp_map = data->map.tmp_map->next;
	// }