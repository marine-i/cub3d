#include "main.h"

int	parse_texture_path(char *line, char **data)
{
	char	*str;
	char	*tmp;
	int		fd;
	char	buff[1];

	if (*data)
		return (print_error(ERR_ELEM_DUP), FAILURE);
	fd = -1;
	while (*line && (*line == ' ' || (*line >= 9 && *line <= 13)))
		line++;
	tmp = ft_strdup(line);
	if (!tmp)
		return (print_error(ERR_MALLOC), FAILURE);
	str = ft_strtrim(tmp, " \t\n\r\v\f");
	free(tmp);
	if (!str)
		return (print_error(ERR_MALLOC), FAILURE);
	if (check_ext_file(str, ".xpm") == SUCCESS)
		fd = open(str, O_RDONLY);
	if (fd < 0)
		return (free(str), print_error(ERR_TEXT_PATH), FAILURE);
	if (read(fd, buff, 1) < 0)
	{
		close(fd);
		free(str);
		return (print_error(ERR_DIR_FILE), FAILURE);
	}
	// fd = open(str, O_RDONLY); // a retirer?
	*data = str;
	return (close(fd), SUCCESS);
}
