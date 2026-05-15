#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdint.h>

typedef int	(*t_fn)(void);

# define WIN_W 1000
# define WIN_H 800

# define MOVE_SPEED 0.1

# define ERR_MALLOC			"Malloc fail"
# define ERR_ARGS 			"Bad number of arguments"
# define ERR_EXT_FILE		"Invalid file extension"
# define ERR_READ_FILE		"Cannot read/open file"
# define ERR_DIR_FILE		"Is a directory not a file"
# define ERR_TEXT_PATH		"Invalid texture path"
# define ERR_ELEM_DUP		"Invalid texture/color duplicate"
# define ERR_ELEM_FORM		"Invalid texture/color formatting"
# define ERR_FILE_CONF		"Map before config"
# define ERR_FILE_EMPTY		"File is empty"
# define ERR_FILE_ELEM		"Missing elements config"
# define ERR_NO_MAP			"No map found"
# define ERR_MAP_INVALID	"Map invalid"
# define ERR_MAP_PLAYERS	"Too many players"
# define ERR_MAP_NO_PLAYERS	"Map no player"
# define ERR_INIT_MLX		"Failed to init mlx_ptr"
# define ERR_WINDOW			"Failed to create window"
# define ERR_IMG			"Failed to create img"

enum e_status
{
	SUCCESS		= 0,
	FAILURE		= 1,
	MAP			= 3,
	CONTINUE	= 4
	// BREAK 		= 4
};

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color;
	int		ceiling_color;
	int		count_elements;
}	t_textures;

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
	int		width;
	int		check_element;
	int		nb_line_map; // a supp (height?)
	int		map_interrupted;
	int		pos_x; // a supp?
	int		pos_y; // a supp?
	t_list	*tmp_map;
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

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
}	t_draw;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	t_map		map;
	t_player	player;
	t_ray		ray; //ajout Marie
	t_draw		draw; //ajout Marie
	t_img		img; //ajout Marie
}	t_data;

// typedef struct s_game
// {
// 	t_map		map;
// 	t_player	player;
// 	t_ray		ray;
// t_draw		draw;
// 	t_data		data;
// }	t_game;


// PARSING
int		parsing(char *file, t_data *data);
int		read_file_content(int fd, t_data *data);
int		check_ext_file(char *file, char *ext_file);

// PARSING FILL MAP
int		fill_map(t_data *data);
int		check_map(t_data *data);
int		is_player(char c);

// PARSING COLORS
int		parse_color(char *line, int *data);

// PARSING TEXTURES
int		parse_texture_path(char *line, char **data);
int		handle_texture(char *str, char **path);
int		handle_color(char *str, int *color);

// PARSING UTILS
void	empty_gnl(int fd);
int		is_space(char c);
int		check_error_file(t_data *data);
int		check_ext_file(char *file, char *ext_file);

// UTILS
void	print_error(char *msg);
void	*ft_free(char **result, int i);
// void	cleanup(t_data *data);
void	free_all(t_data *data);
void	free_split(char **tab);

//fin partie Marine debut Marie

// DDA ALGO
void	init_dda(t_ray *ray, t_player *player);
void	perform_dda(t_map *map, t_ray *ray);
void	wall_dist(t_ray *ray);

// RAY CAST
void    init_ray_dir(t_ray *ray,t_player *player, int x);
void	wall_projection(t_draw *draw, t_ray *ray);

// DRAW
int		init_mlx(t_data *data);
void	pixel_put(t_img *img, int x, int y, int color);
void	draw_column(t_data *data, int x);
void	render_frame(t_data *data);

// MINIMAP
void	draw_square(t_data *data, int start_x, int start_y, int color);
void	draw_minimap(t_data *data);
void	draw_player_on_minimap(t_data *data);

#endif