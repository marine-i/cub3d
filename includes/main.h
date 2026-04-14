#ifndef MAIN_H
# define MAIN_H

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define ERR_MALLOC			"Malloc fail"
# define ERR_ARGS 			"Bad number of arguments"
# define ERR_EXT_FILE		"Invalid file extension"
# define ERR_READ_FILE		"Cannot read/open file"
# define ERR_DIR_FILE		"Is a directory not a file"
# define ERR_TEXT_PATH		"Invalid texture path"
# define ERR_ELEM_DUP		"Invalid texture/color duplicate"
# define ERR_FILE_CONF		"Map before config"
# define ERR_FILE_EMPTY		"File is empty"
# define ERR_FILE_ELEM		"Missing elements config"
# define ERR_NO_MAP			"No map found"

enum e_status
{
	SUCCESS 	= 0,
	FAILURE 	= 1,
	MAP 		= 3,
	CONTINUE 	= 4
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
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		widht;
}	t_map;

typedef struct s_game
{

}	t_game;

typedef struct data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	t_map		map;
	t_player	player;
	t_game		game;
}	t_data;


// PARSING
int		parsing(char *file, t_data *data);
int		read_file_content(int fd, t_data *data);

// UTILS
void	print_error(char *msg);
void	cleanup(t_data);
void	*ft_free(char **result, int i);

#endif