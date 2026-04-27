#include "main.h"

int	handle_texture(char *str, char **path)
{
	if (is_space(*str) == SUCCESS)
		return (parse_texture_path(str, path));
	else
		return(print_error(ERR_ELEM_FORM), FAILURE);
}

int	handle_color(char *str, int *color)
{
	if (is_space(*str) == SUCCESS)
		return (parse_color(str, color));
	else
		return(print_error(ERR_ELEM_FORM), FAILURE);
}

int	parse_texture_path(char *line, char **data)
{
	char	*str;
	int		fd;
	char	buff[1];

	if (*data)
		return (print_error(ERR_ELEM_DUP), FAILURE);
	fd = -1;
	str = ft_strtrim(line, " \t\n\r\v\f");
	if (!str)
		return (print_error(ERR_MALLOC), FAILURE);
	if (check_ext_file(str, ".xpm") == SUCCESS)
		fd = open(str, O_RDONLY);
	if (fd < 0)
		return (free(str), print_error(ERR_TEXT_PATH), FAILURE);
	if (read(fd, buff, 1) < 0)
		return (close(fd), free(str), print_error(ERR_DIR_FILE), FAILURE);
	*data = str;
	return (close(fd), SUCCESS);
}
