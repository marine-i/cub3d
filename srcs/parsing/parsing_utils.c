#include "main.h"

int	check_ext_file(char *file, char *ext_file)
{
	char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ext_file, 5) != 0
		|| ext == file || ft_strlen(ext) != 4)
		return (FAILURE);
	return (SUCCESS);
}

int	check_error_file(t_data *data)
{
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

void	empty_gnl(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while(tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (SUCCESS);
	return (FAILURE);
}
