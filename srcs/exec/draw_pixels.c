#include "cub3d.h"

//Initialiser la MLX
int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "cub3D");
	if (!data->win_ptr)
		return (1);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (!data->img.img_ptr)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp,
			&data->img.line_len,
			&data->img.endian);
	if (!data->img.addr)
		return (1);
	return (0);
}

//Fonction pour dessiner un pixel
void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}


#define CEILING_COLOR 0x87CEEB
#define WALL_COLOR    0x808080
#define FLOOR_COLOR   0x654321

void	draw_column(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->draw.draw_start)
	{
		pixel_put(&data->img, x, y, CEILING_COLOR);
		y++;
	}
	while (y <= data->draw.draw_end)
	{
		pixel_put(&data->img, x, y, WALL_COLOR);
		y++;
	}
	while (y < WIN_H)
	{
		pixel_put(&data->img, x, y, FLOOR_COLOR);
		y++;
	}
}

// void	render_frame(t_data *data)
// {
// 	int	x;

// 	x = 0;
// 	while (x < WIN_W)
// 	{
// 		init_ray_dir(&data->ray, &data->player, x);
// 		init_dda(&data->ray, &data->player);
// 		perform_dda(&data->map, &data->ray);
// 		wall_dist(&data->ray);
// 		wall_projection(&data->draw, &data->ray);
// 		draw_column(data, x);
// 		x++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr,
// 		data->win_ptr,
// 		data->img.img_ptr,
// 		0, 0);
// }

void	render_frame(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		init_ray_dir(&data->ray, &data->player, x);
		init_dda(&data->ray, &data->player);
		perform_dda(&data->map, &data->ray);
		wall_dist(&data->ray);
		wall_projection(&data->draw, &data->ray);
		draw_column(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr,
		data->img.img_ptr,
		0, 0);
}

