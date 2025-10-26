/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:57:10 by yvieira-          #+#    #+#             */
/*   Updated: 2025/10/26 14:05:47 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keycaps.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_HEIGHT 720
# define WIN_WIDTH 1080

# define MINIMAP_VIEW_WIDTH 10
# define MINIMAP_VIEW_HEIGHT 10

# define MOVE_SPEED 1
# define BLOCK_SIZE 64
# define PLAYER_SIZE 16
# define PI 3.14159265359
# define FOV 0.86

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_minimap
{
	int	mini_block_size;
	int	player_map_x;
	int	player_map_y;
	int	map_start_x;
	int	map_start_y;
}		t_minimap;

typedef struct s_list
{
	char *line;
	struct s_list *next;

}		t_list;

typedef struct s_image
{
	char	**matriz;
	void	*img;
	char	*addr;

}			t_image;

typedef struct s_parse_map
{
	int num_lines;
	char vision_player;
	float initial_y;
	float initial_x;
	char *texture_so;
	char *texture_no;
	char *texture_we;
	char *texture_ea;
	t_list *list;
	int	w_texture;
	int	f_rgb[3];
	int	c_rgb[3];
	int	map_start_line;
	int	largest_line;
	char **map;
	char	*file_path;
	int		map_size;

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
	int			map_height;
	int			map_width;
	t_player	player;
	t_minimap	minimap;
	char		**map;
	int			floor_color;
	int			ceiling_color;
	t_tex		textures[4];
	t_parse_map	map_data;
}	t_game;

// --- Functions ---

//minimap.c
void				draw_minimap(t_game *game);
void				draw_player_minimap(t_game *game);

// init.c
void				init_game(t_game *game);
void				init_player(t_game *game);
char				**get_map(void);
int					init_win(t_game *game);

// hooks.c
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
void				move_player(t_player *player, char **map);
int					exit_program(t_game *game);

// render.c
void				put_pixel(int x, int y, int color, t_game *game);
void				clear_image(t_game *game);
void				draw_map(t_game *game);
void				draw_player(t_game *game);
int					render_loop(t_game *game);
void				raycasting(t_game *game);
void				draw_filled_square(t_point start, int size, int color,
						t_game *game);
void				calculate_step_and_side_dist(t_ray *ray, t_player *player);
void				perform_dda(t_ray *ray, t_game *game);
void				init_ray(t_ray *ray, t_player *player, int x);
void				draw_vertical_line(t_game *game, t_ray *ray, int x);

//	parse
int					extencion_map(char *filename);
bool				line_is_empty(char *line);
int					valid_line(char *line, t_parse_map **data);
void				init_data(t_parse_map *data);
int					parse_map_file(int fd, t_parse_map *data);
int					all_configs_loaded(t_parse_map *data);
void				parse_colors_f(char *rgb_str, t_parse_map *data);
void				parse_colors_c(char *rgb_str, t_parse_map *data);
void				parse_config_line(char *line, t_parse_map *data);
void				valid_map(t_parse_map *data, char *first_line, int fd);

// utils
void				free_map(char **map);
void				free_game_data(t_game *game);
int					rgb_to_int(int r, int g, int b);
int					is_valid_map_line(char *line);
void				find_player(char **map_copy, t_parse_map *data,
						char *char_player);
int					flood_fill(char **map_copy, int y, int x, int map_height);
void				load_textures(t_game *game);

void				free_list(t_list **head);
void				free_struct(t_parse_map *data, char *menssage);
void				little_validade(t_parse_map *data, char *current_line);
void				ft_lsadd_back(t_list **head, t_list *new);
t_list				*create_node(char *content);
void				map_size_list(t_parse_map *data);
char				**duplicate_map(t_parse_map *data);
void				free_textures(t_parse_map *data);
void				close_all(void);
int					validate_textures(t_game *game);

#endif