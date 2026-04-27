#include "main.h"

int	check_elements(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]) == SUCCESS)
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (CONTINUE);
	if (ft_strncmp(&str[i], "NO", 2) == 0)
		return (handle_texture(&str[i + 2], &data->textures.no_path));
	if (ft_strncmp(&str[i], "SO", 2) == 0)
		return (handle_texture(&str[i + 2], &data->textures.so_path));
	if (ft_strncmp(&str[i], "WE", 2) == 0)
		return (handle_texture(&str[i + 2], &data->textures.we_path));
	if (ft_strncmp(&str[i], "EA", 2) == 0)
		return (handle_texture(&str[i + 2], &data->textures.ea_path));
	if (ft_strncmp(&str[i], "F", 1) == 0)
		return (handle_color(&str[i + 1], &data->textures.floor_color));
	if (ft_strncmp(&str[i], "C", 1) == 0)
		return (handle_color(&str[i + 1], &data->textures.ceiling_color));
	return (MAP);
}

int	check_start_end_line(char *str, int len, int i)
{
	int	end;

	end = 0;
	if (str[i] == '0' || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W') // ajouter dir
		return (FAILURE);
	end = len - 1;
	while (end >= 0 && is_space(str[end]) == SUCCESS)
		end--;
	if (end >= 0 && (str[end] == '0' || str[end] == 'N' || str[end] == 'S' || str[end] == 'E' || str[end] == 'W'))
		return (FAILURE);
	return (SUCCESS);
}

int check_map_chars(char *str, int i, t_data *data)
{
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			data->map.check_element++;
			if (data->map.check_element > 1)
				return (print_error(ERR_MAP_PLAYERS), FAILURE);
		}
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\0' && str[i] != ' ') // tab a retirer?
			return(print_error(ERR_MAP_INVALID), FAILURE);
		i++;
	}
	return (SUCCESS);
}

// element valide : 0 n s e w " "
int	check_map_line(char *str, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
		len--;
	}
	if (len > data->map.width)
		data->map.width = len;
	while (str[i] && str[i] == ' ')
		i++;
	if (check_start_end_line(str, len, i) == FAILURE)
		return (print_error(ERR_MAP_INVALID), FAILURE);
	return (check_map_chars(str, i, data));
}

int	check_ret_elements(t_data *data, int ret, char *line)
{
	if (ret == FAILURE)
		return (FAILURE);
	else if (ret == SUCCESS)
		data->textures.count_elements++;
	else if (ret == MAP)
	{
		if (data->map.map_interrupted == 1)
			return (print_error(ERR_MAP_INVALID), FAILURE);
		if (data->textures.count_elements < 6)
			return (print_error(ERR_FILE_CONF), FAILURE);
		if (check_map_line(line, data) == FAILURE)
			return (FAILURE);
		data->map.nb_line_map++;
		ft_lstadd_back(&data->map.tmp_map, ft_lstnew(ft_strdup(line)));
	}
	else if (ret == CONTINUE && data->map.nb_line_map > 0) // si on a deja commencé à lire la map et qu'on tombe sur une ligne vide ou que c'est la fin du fichier
		data->map.map_interrupted = 1;
	return (SUCCESS);
}

int	read_file_content(int fd, t_data *data)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	if (!line)
		return (print_error(ERR_FILE_EMPTY), FAILURE);
	ret = CONTINUE;
	while (line)
	{
		ret = check_elements(line, data);
		if (check_ret_elements(data, ret, line) == FAILURE)
		{
			empty_gnl(fd);
			return (free(line), FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_error_file(data) == FAILURE)
		return (free(line), FAILURE);
	free(line);
	return (SUCCESS);
}


// while (data->map.tmp_map)
// 	{
// 		printf("%s\n", (char *)data->map.tmp_map->content);
// 		data->map.tmp_map = data->map.tmp_map->next;
// 	}