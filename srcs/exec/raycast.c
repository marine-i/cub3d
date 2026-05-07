#include "cub3d.h"

/*function to init ray direction*/
void    init_ray_dir(t_ray *ray,t_player *player, int x)
{
	ray->camera_x = 2.0 * x / (double)WIN_W - 1.0;
	ray->raydir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->raydir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (ray->raydir_x == 0)
		ray->delta_dist_x = 1e30;                                                 
	else
		ray->delta_dist_x = fabs(1.0 / ray->raydir_x);
	if(ray->raydir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->raydir_y);
	ray->hit_wall = 0;
}


void	wall_projection(t_draw *draw, t_ray *ray)
{
	draw->line_height = (int)(WIN_H / ray->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + WIN_H / 2;
	draw->draw_end = draw->line_height / 2 + WIN_H / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	if (draw->draw_end >= WIN_H)
		draw->draw_end = WIN_H - 1;
}
