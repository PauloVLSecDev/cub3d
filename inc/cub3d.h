/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:03:24 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/09/15 01:31:17 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include </workspaces/ft_template_repo-main/minilibx-linux/mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define PIXEL_COLOR 0x00FF0000
# define MOVE_SPEED 5
# define PLAYER_CHAR "NSWE"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keycaps.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_image
{
	char	**matriz;
	void	*img;
	char	*addr;

}	t_image;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		left_rotate;
	int		right_rotate;
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


#endif