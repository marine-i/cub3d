#include "main.h"

int	check_ext_file(char *file)
{
	char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 5) != 0 || ext == file || ft_strlen(ext) != 4)
		return (1);
	return (0);
}

int	parsing(char *file, t_data *data)
{
	int	fd;
	int	fd_dir;

	(void)data; // rm
	if (check_ext_file(file))
		return (print_error(ERR_EXT_FILE), 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error(ERR_READ_FILE), 1);
	fd_dir = open(file, __O_DIRECTORY);
	if (fd_dir >= 0)
	{
		close (fd);
		close (fd_dir);
		return (print_error(ERR_DIR_FILE), 1);
	}
	// if (read_file_content(fd, data))
	close (fd);
	return (0);
}
