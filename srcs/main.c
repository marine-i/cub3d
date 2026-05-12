#include "cub3d.h"

void	init_data(t_data *data)
{
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
}

int	close_window(void *param)
{
	t_data *data;
	data = (t_data *)param;
	free_all(data);
	exit(1);
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 65307)
		close_window(game);
	// else
	// 	handle_mov(keycode, game);
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
	mlx_hook(data.win_ptr, 2, 1, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
	return (EXIT_SUCCESS);
}
// int	main(void)
// {
// 	t_data	data;

// 	init_test_map(&data);
// 	init_test_player(&data);
// 	if (init_mlx(&data))
// 		return (1);
// 	render_frame(data);
// 	mlx_loop(data.mlx.mlx_ptr);
// 	return (0);
// }