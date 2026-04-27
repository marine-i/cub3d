#include "main.h"

int	parsing(char *file, t_data *data)
{
	int		fd;
	char	buff[1];

	if (check_ext_file(file, ".cub") == FAILURE)
		return (print_error(ERR_EXT_FILE), FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error(ERR_READ_FILE), FAILURE);
	if (read(fd, buff, 1) < 0)
	{
		close(fd);
		return (print_error(ERR_DIR_FILE), FAILURE);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (read_file_content(fd, data) == FAILURE)
		return (close(fd), FAILURE);
	// fill map (data.tmpmap to char **map)
	// printf("nb line map : %d\n", data->map.nb_line_map);
	// check la map floodfill
	close (fd);
	return (SUCCESS);
}
