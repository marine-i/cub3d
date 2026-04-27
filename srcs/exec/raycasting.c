/*
Formule principale du raycasting :

Rayon selon la colonne x de l'écran :
- cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space
- rayDirX = dirX + planeX * cameraX;
- rayDirY = dirY + planeY * cameraX;

Pas entre les lignes de la grille :
- deltaDistX = |1 / rayDirX|;
- deltaDistY = |1 / rayDirY|;

Distance au mur :
- perpWallDist = sideDistX - deltaDistX; // si le mur est vertical
- perpWallDist = sideDistY - deltaDistY; // si le mur est horizontal.

Hauteur du mur à dessiner :
- lineHeight = (int)(screenHeight / perpWallDist);


Resume pour chaque colonne de l'écran :
1. Calculer la direction du rayon pour la colonne x.
2. Initialiser les variables pour le DDA (sideDistX, sideDistY, stepX, stepY):
	1. Trouver la case de depart du rayon (mapX, mapY).
	2. calcule deltaDistX et deltaDistY pour le rayon.
3. Effectuer le DDA pour trouver la première intersection avec un mur.
4. Calculer la distance perpendiculaire au mur (perpWallDist).
5. Calculer la hauteur du mur à dessiner (lineHeight). 
*/

#include "cub3d.h"

// formule:
/*/
void    raycast(t_ray *ray, t_player *player)
{
	int x; //x = numero de colonne

	// le rayon :
	ray->camera_x = 2 * x / WIN_W -1;
	// donc:
	ray->raydir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->raydir_y = player->dir_y + player->plane_y * ray->camera_x;

	ray->delta_dist_x = fabs(1 / ray->raydir_x); //voir si bonne formule
	ray->delta_dist_y = fabs(1 / ray->raydir_y); //voir si bonne formule
	//DDA
	if(ray->step_x = 1)
	{
		//ray va vers la droite
		// la prochaine ligne verticale est a :
		ray->map_x + 1;
		// la distance horizontale vaut:
		ray->map_x + 1 - player->pos_x;
		// on convertit ca en distance le long du rayon:
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x);
	}
	if(ray->step_x = -1)
	{
		//ray va vers la gauche
		// la prochaine ligne verticale est a :
		ray->map_x;
		  // la distance horizontale vaut:
		ray->map_x - player->pos_x;
		// on convertit ca en distance le long du rayon:
		ray->side_dist_x = (ray->map_x - player->pos_x);
	}
	if(ray->step_y = 1)
	{
		//ray va vers le bas
		// la prochaine ligne verticale est a :
		ray->map_y + 1;
		// la distance horizontale vaut:
		ray->map_y + 1 - player->pos_y;
		// on convertit ca en distance le long du rayon:
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y);
	}
	if(ray->step_y = -1)
	{
		//ray va vers le haut
		// la prochaine ligne verticale est a :
		ray->map_y;
		// la distance horizontale vaut:
		ray->map_y - player->pos_y;
		// on convertit ca en distance le long du rayon:
		ray->side_dist_y = (ray->map_y - player->pos_y);
	}
	//la distance au mur:
	if (ray->side = 0) //si on touche un cote vertical
	{
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	}
	if (ray->side = 1) //si o touche un cote horizontal
	{
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;

	}
}
*/

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

/*function to initial side distances*/
void	init_dda(t_ray *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x);
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y);
	}
}

void	perform_dda(t_map *map, t_ray *ray)
{
	while(ray->side == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map[ray->map_x][ray->map_y] > 0) // >0 ou possiblite de mettre =='1' -> voir si idem
			ray->side = 1;
	}
}

void	wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
