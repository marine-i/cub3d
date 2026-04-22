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

int	parsing(char *file, t_data *data)
{
	int	fd;
	int	fd_dir;

	if (check_ext_file(file, ".cub") == FAILURE)
		return (print_error(ERR_EXT_FILE), FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error(ERR_READ_FILE), FAILURE);
	fd_dir = open(file, __O_DIRECTORY);
	if (fd_dir >= 0)
	{
		close (fd);
		close (fd_dir);
		return (print_error(ERR_DIR_FILE), FAILURE);
	}
	if (read_file_content(fd, data) == FAILURE)
		return (FAILURE);
	// fill map
	printf("nb line map : %d\n", data->map.nb_line_map);

	// check la map

	close (fd);
	return (SUCCESS);
}
