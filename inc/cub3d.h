/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* cub3d.h                                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/09/15 01:03:24 by yurivieirad       #+#    #+#             */
/* Updated: 2025/09/23 19:30:06 by yurivieirad      ###   ########.fr       */
/* */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "keycaps.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920

# define MOVE_SPEED 3
# define BLOCK_SIZE 64
# define PLAYER_SIZE 8
# define PI 3.14159265359

typedef struct s_image
{
	char	**matriz;
	void	*img;
	char	*addr;

}			t_image;

typedef struct s_parse_map
{
	int num_lines;
	int	wall;
	int empyt;
	char *Texture_SO;
	char *Texture_NO;
	char *Texture_WE;
	char *Texture_EA;
	int	W_texture;
	int	F_rgb[3];
	int	C_rgb[3];
	int	map_start_line;
	char **map;

} 			t_parse_map;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	char		**map;
	int			floor_color;
	int			ceiling_color;
	t_tex		textures[4];
}	t_game;

// --- Protótipos de Funções ---

// init.c
void	init_game(t_game *game);
void	init_player(t_player *player);
char	**get_map(void);
int		init_win(void);

// hooks.c
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	move_player(t_player *player, char **map);
int		exit_program(t_game *game);

// render.c
void	put_pixel(int x, int y, int color, t_game *game);
void	clear_image(t_game *game);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		render_loop(t_game *game);
void	raycasting(t_game *game);
void	draw_minimap(t_game *game);
void	draw_player_minimap(t_game *game);
void	draw_filled_square(int x, int y, int size, int color, t_game *game);

//	parse
int			extencion_map(char *filename);
bool 		line_is_empty(char *line);
int			valid_line(char *line, t_parse_map **data);
void		init_data(t_parse_map *data);
void		parse_map_file(int fd, t_parse_map *data);
int			all_configs_loaded(t_parse_map *data);
void		parse_colors(char *rgb_str, int *color_array);
void		parse_config_line(char *line, t_parse_map *data);
void		valid_map(t_parse_map *data, char *first_line, int fd);
#endif