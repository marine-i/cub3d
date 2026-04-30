#include "main.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (SUCCESS);
	return (FAILURE);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '0'
				|| is_player(data->map.map[y][x]) == SUCCESS)
			{
				if (y == 0 || y == (data->map.nb_line_map - 1)
					|| x == 0 || x == data->map.width - 1)
					return (print_error(ERR_MAP_INVALID), FAILURE);
				if (data->map.map[y][x + 1] == 'X'
					|| data->map.map[y - 1][x] == 'X'
					|| data->map.map[y + 1][x] == 'X'
					|| data->map.map[y][x - 1] == 'X')
					return (print_error(ERR_MAP_INVALID), FAILURE);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
