/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:03:24 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/09/18 20:43:18 by yurivieirad      ###   ########.fr       */
/*                                                                            */
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

# define WIN_WIDTH 960
# define WIN_HEIGHT 640
# define MOVE_SPEED 3
# define BLOCK_SIZE 64
# define PLAYER_SIZE 8
# define PI 3.14159265359

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
}	t_game;

// --- Protótipos de Funções ---

// init.c
void	init_game(t_game *game);
void	init_player(t_player *player);
char	**get_map(void);

// hooks.c
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player, char **map);
int		exit_program(t_game *game);

// render.c
void	put_pixel(int x, int y, int color, t_game *game);
void	clear_image(t_game *game);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		render_loop(t_game *game);

#endif