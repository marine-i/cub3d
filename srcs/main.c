#include "cub3d.h"

void	init_data(t_data *data)
{
	// ft_memset(data, 0, sizeof(t_data));
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;

	data->textures.so_path = NULL;
	data->textures.no_path = NULL;
	data->textures.we_path = NULL;
	data->textures.ea_path = NULL;
	data->textures.floor_color = -1;
	data->textures.ceiling_color = -1;
	data->textures.count_elements = 0;

	data->map.height = -1;
	data->map.width = -1;
	data->map.map = NULL;
	data->map.check_element = 0;
	data->map.nb_line_map = 0;
	data->map.map_interrupted = 0;
	data->map.tmp_map = NULL;

	data->player.pos_x = -1;
	data->player.pos_y = -1;
	data->player.dir_x = -1;
	data->player.dir_y = -1;
	data->player.plane_x = -1;
	data->player.plane_y = -1;
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_all(data);
	exit(1);
}

void	handle_mov(int keycode, t_data *data)
{
	double new_x;
	double new_y;

	new_x = data->player.pos_x;
	new_y = data->player.pos_y;
	if (keycode == 119 || keycode == 65362) // W et ^
	{
		new_x += data->player.dir_x * MOVE_SPEED;
		new_y += data->player.dir_y * MOVE_SPEED;
	}
	else if (keycode == 115 || keycode == 65364)
	{
		new_x -= data->player.dir_x * MOVE_SPEED;
		new_y -= data->player.dir_y * MOVE_SPEED;
	}
	if (data->map.map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map.map[(int)new_y][(int)data->player.pos_x] != '1')
		data->player.pos_y = new_y;
	render_frame(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else
		handle_mov(keycode, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (print_error(ERR_ARGS), EXIT_FAILURE);
	init_data(&data);
	if (parsing(av[1], &data) == FAILURE)
		return (free_all(&data), EXIT_FAILURE);
	init_mlx(&data);
	render_frame(&data);
	mlx_hook(data.win_ptr, 2, 1, (t_fn)(intptr_t)key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, (t_fn)(intptr_t)close_window, &data);
	// mlx_loop_hook(data.mlx_ptr, &render_frame, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
	return (EXIT_SUCCESS);
}
