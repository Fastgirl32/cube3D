/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:50:17 by phnowak           #+#    #+#             */
/*   Updated: 2023/12/03 20:59:58 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define FAIL 1
# define OK 2

typedef struct s_index
{
	int				i;
	int				j;
	int				k;
}					t_index;

typedef struct s_addr
{
	char			*img;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_addr;

typedef struct s_map
{
	char			**map;
	char			*info;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			**ceiling;
	char			**floor;
}					t_map;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	char			spawn_dir;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_texture
{
	t_addr			addr;
	void			*img;
	char			*path;
	int				width;
	int				height;

}					t_texture;

typedef struct s_ray
{
	double			pos_x;
	double			pos_y;
	double			camera;
	double			dir_x;
	double			dir_y;
	double			raydir_x;
	double			raydir_y;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			plane_x;
	double			plane_y;
	double			olddir_x;
	double			oldplane_x;
	int				mapx;
	int				mapy;
	int				hit;
	int				side;
	int				stepx;
	int				stepy;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	int				texy;
	double			wallx;
	double			step;
	double			texpos;
	unsigned int	color;
}					t_ray;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			height;
	double			screen_width;
	double			screen_height;
	int				textwidth;
	int				textheight;
	int				count2;
	char			**fcolor;
	char			**ccolor;
	t_map			*map;
	t_ray			*ray;
	t_img			*img;
	t_texture		n;
	t_texture		s;
	t_texture		e;
	t_texture		w;
	t_player		*player;
}					t_game;

bool				check_map(t_game *game);
void				ray_casting(t_game *game);
void				open_window(t_game *game);
void				create_bg(t_game *game);
void				calc_dist(t_game *game, t_ray *ray);
void				img_pxl_put(t_game *game, int x, int y, int color);
t_texture			open_texture(t_game *game, char *path);
void				open_all_textures(t_game *game);
void				error(char *error, t_game *game);
void				init_structs(t_game *game, char *input);
char				**load_map(char *input);
int					sort_info(t_game *game);
void				init_raycast(int x, t_ray *ray, t_player *player,
						t_game *game);
void				set_player_spawn(t_game *game);
int					key_input(int key, t_game *game);
void				form_texture(t_game *game, t_ray *ray, int x);
void				free_all(t_game *game);
char				**get_rgb(char *info, int *i, char **plane_position,
						t_game *game);
bool				already_found(char *path, t_game *game);
char				*read_inputfile(char *file);
char				*get_path(char *info, int *i, t_game *game);
void				cut_map(t_game *game, int i, char *info);
int					count_height(char *info, int i, t_game *game);
void				print_test(t_game *game);
void				input_check(int ac, char *av);
t_game				*game_start(char *input);
int					close_window(t_game *game);
void				split_info(t_game *game);
void				player_turn_left(t_game *game);
void				player_turn_right(t_game *game);
void				player_move_backward(t_game *game);
void				player_move_forward(t_game *game);
void				player_move_right(t_game *game);
void				player_move_left(t_game *game);
void				process_cub(t_game *game, char *info, int *i);
void				check_color(t_game *game);
void				check_access(t_game *game);
void				init_player(t_game *game);
char				*read_inputfile(char *file);
bool				found_str(char *info, char *tofind, t_game *game);
void				found_all_identifier(t_game *game, int *i, char *info);
char				*get_path2(char *info, int *i, t_game *game);
#endif
