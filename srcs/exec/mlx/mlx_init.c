#include "main.h"

void	*init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		print_error(ERR_INIT_MLX);
		return (FAILURE);
	}
	return (data->mlx_ptr);
}
