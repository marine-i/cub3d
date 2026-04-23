#include "main.h"

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
		return (close(fd), FAILURE);
	// fill map
	// printf("nb line map : %d\n", data->map.nb_line_map);
	// check la map
	close (fd);
	return (SUCCESS);
}
