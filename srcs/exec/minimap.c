#include "cub3d.h"

#define MINI_TILE 10
#define MINI_OFFSET_X 10
#define MINI_OFFSET_Y 10

void	draw_square(t_data *data, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_TILE)
	{
		x = 0;
		while (x < MINI_TILE)
		{
			pixel_put(&data->img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

#define MINI_WALL_COLOR   0xFFFFFF
#define MINI_FLOOR_COLOR  0x000000
#define MINI_PLAYER_COLOR 0xFF0000

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.map[y][x])
		{
			screen_x = MINI_OFFSET_X + x * MINI_TILE;
			screen_y = MINI_OFFSET_Y + y * MINI_TILE;
			if (data->map.map[y][x] == '1')
				draw_square(data, screen_x, screen_y, MINI_WALL_COLOR);
			else
				draw_square(data, screen_x, screen_y, MINI_FLOOR_COLOR);
			x++;
		}
		y++;
	}
	draw_square(data,
		MINI_OFFSET_X + (int)(data->player.pos_x * MINI_TILE),
		MINI_OFFSET_Y + (int)(data->player.pos_y * MINI_TILE),
		MINI_PLAYER_COLOR);
}

void	draw_player_on_minimap(t_data *data)
{
	int	px;
	int	py;

	px = MINI_OFFSET_X + (int)(data->player.pos_x * MINI_TILE);
	py = MINI_OFFSET_Y + (int)(data->player.pos_y * MINI_TILE);
	pixel_put(&data->img, px, py, MINI_PLAYER_COLOR);
	pixel_put(&data->img, px + 1, py, MINI_PLAYER_COLOR);
	pixel_put(&data->img, px, py + 1, MINI_PLAYER_COLOR);
	pixel_put(&data->img, px + 1, py + 1, MINI_PLAYER_COLOR);
}
