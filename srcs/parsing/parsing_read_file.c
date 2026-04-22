#include "main.h"

//  check valid map

int	check_nb_virgule(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j > 2 || j < 2)
		return (FAILURE);
	return (SUCCESS);
}

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0' || (str[i] == '-' || str[i] == '+'))
		return (FAILURE);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (FAILURE);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0')
		return (FAILURE);
	return (SUCCESS);
}

static int	check_limits(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (!str)
		return (FAILURE);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 255)
			return (FAILURE);
		i++;
	}
	if (nb < 0)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_str_color(char *str)
{
	if (!str)
		return (FAILURE);
	if (is_digit(str) == FAILURE || check_limits(str) == FAILURE)
		return (printf("ca va pas c'est trop petit ou trop grand\n"), FAILURE); // a changer
	return (SUCCESS);
}

int	parse_color(char *line, int *data)
{
	char	**result;
	int		*tab_color;
	int		i;

	if (*data != -1)
		return (print_error(ERR_ELEM_DUP), FAILURE); // free si tab alloué
	if (check_nb_virgule(line) == FAILURE)
		return (FAILURE);
	result = ft_split(line, ',');
	if (!result || !result[0] || !result[1] || !result[2]) // a voir
	{
		ft_free(result, 4);
		return (print_error(ERR_MALLOC), FAILURE); // si pb de parsing msg different
	}
	tab_color = malloc(sizeof(int) * 3);
	if (!tab_color)
	{
		ft_free(result, 4);
		return (print_error(ERR_MALLOC), FAILURE);
	}
	i = 0;
	while (i < 3)
	{
		if (parse_str_color(result[i]) == FAILURE)
		{
			ft_free(result, 4);
			free(tab_color); // free le tableau en entier
			return (FAILURE);			
		}
		tab_color[i] = ft_atoi(result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	*data = (tab_color[0] << 16 | tab_color[1] << 8 | tab_color[2]);
	free(tab_color);
	return (SUCCESS);
}

int	parse_texture_path(char *line, char **data) // rajouter le .xmp
{
	char	*str;
	int		fd;
	int		i;

	if (*data)
		return (print_error(ERR_ELEM_DUP), FAILURE);
	i = 0;
	fd = -1;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	str = ft_strdup(&line[i]);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		str[i] = '\0';
	if (check_ext_file(str, ".xpm") == SUCCESS)
		fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		return (print_error(ERR_TEXT_PATH), FAILURE);
	}
	close(fd);
	*data = str;
	free(str);
	return (SUCCESS);
}

int	check_elements(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (CONTINUE);
	if (strncmp(&str[i], "NO ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.no_path));
	if (strncmp(&str[i], "SO ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.so_path));
	if (strncmp(&str[i], "WE ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.we_path));
	if (strncmp(&str[i], "EA ", 3) == 0)
		return (parse_texture_path(&str[i + 3], &data->textures.ea_path));
	if (strncmp(&str[i], "F ", 2) == 0)
		return (parse_color(&str[i + 2], &data->textures.floor_color));
	if (strncmp(&str[i], "C ", 2) == 0)
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
		if (str[0] == '\n')
			printf("ligne\n");
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			printf("le char est : %c\n", str[i]);
			data->map.check_element++;
			printf("il y a %d\n", data->map.check_element);
			if (data->map.check_element > 1)
				printf("il y a trop de player\n");
		}
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != ' ') // tab?
			printf("mauvais element\n");
		i++;
	}
	return (i);
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
		if (ret == FAILURE)
			return (free(line), FAILURE);
		else if (ret == SUCCESS)
			data->textures.count_elements++;
		else if (ret == CONTINUE && data->map.nb_line_map > 0)
		{
			// free
			printf("on est ici\n");
		}
		else if (ret == MAP)
		{
			if (data->textures.count_elements < 6)
			{
				free(line);
				return (print_error(ERR_FILE_CONF), FAILURE);
			}
			data->map.nb_line_map++;
			check_map_line(line, data);
			// return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (data->textures.count_elements < 6)
		return (print_error(ERR_FILE_ELEM), FAILURE);
	if (data->map.nb_line_map == 0)
		return (print_error(ERR_NO_MAP), FAILURE);
	if (data->map.map == NULL && data->textures.count_elements < 6)
		return (print_error(ERR_FILE_EMPTY), FAILURE);
	if (data->map.check_element == 0)
		printf("manque player\n");
	return (SUCCESS);
}
