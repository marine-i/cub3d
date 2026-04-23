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
