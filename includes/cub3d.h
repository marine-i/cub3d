#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
// # include "libft.h"
// # include "mlx.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>

# define WIN_W 1000
// # define WIN_H 800
// # define ANGLE 0.5

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double  plane_x; //vecteur perpendiculaire a dir represente la largeur de la camera
	double  plane_y;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		widht;
	int		check_element;
	int		nb_line_map;
	int		map_interrupted;
}	t_map;

typedef struct s_ray
{
	double  camera_x;
	double  raydir_x;
	double  raydir_y;
	int     map_x;
	int     map_y;
	double  delta_dist_x;
	double  delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int     step_x;
	int     step_y;
	int		side;
	int		hit_wall; //variable pour savoir si je touche ou non un mur
}   t_ray;


#endif