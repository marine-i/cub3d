#include "main.h"

// check NO SO WE EA et recuperer le path
// check si valid couleur et stocker
// check si map avant ou apres, check valid map

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}


int	parse_texture_path(char *line, char **data)
{
	char	*str;
	int		fd;
	int		i;

	if (*data)
		return (print_error(ERR_TEXT_DUP), -1);
	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	str = ft_strdup(&line[i]);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		str[i] = '\0';
	printf("le path est : %s\n", str);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		return (print_error(ERR_TEXT_PATH), -1);
	}
	close(fd);
	*data = str;
	return (1);
}

int	check_elements(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	if (strncmp(&str[i], "NO ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.no_path));
	if (strncmp(&str[i], "SO ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.so_path));
	if (strncmp(&str[i], "WE ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.we_path));
	if (strncmp(&str[i], "EA ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.ea_path));
	return (2);
}


// si 
int	read_file_content(int fd, t_data *data)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	if (!line)
		return (print_error(ERR_FILE_EMPTY), 1);
	while (line)
	{
		ret = check_elements(line, data);
		if (ret == -1)
			return (free(line), 1);
		else if (ret == 1)
			data->textures.count_elements++;
		else if (ret == 2)
		{
			if (data->textures.count_elements < 4)
			{
				free(line);
				return (print_error(ERR_FILE_CONF), 1);
			}
			printf("map\n"); // parse_map
			data->map.map = malloc(sizeof(2));
			data->map.map[0] = ft_strdup(line);
			data->map.map[1] = NULL;
			// return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);	
	}
	if (data->textures.count_elements < 4)
		return (print_error(ERR_FILE_ELEM), 1);
	if (data->map.map == NULL)
		return (print_error(ERR_NO_MAP), 1);
	if (data->map.map == NULL && data->textures.count_elements < 4)
		return (print_error(ERR_FILE_EMPTY), 1);
	return (0);
}
