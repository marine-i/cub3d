#include "main.h"

int	parse_texture_path(char *line, char **data)
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
		return (free(str), print_error(ERR_TEXT_PATH), FAILURE);
	close(fd);
	*data = str;
	return (free(str), SUCCESS);
}
