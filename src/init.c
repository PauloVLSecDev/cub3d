/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:28:12 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/24 21:46:08 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	find_and_set_player_start(t_game *game)
{
	char	cell;

	cell = game->map_data.vision_player;
	if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
	{
		game->player.x = (game->map_data.initial_x * BLOCK_SIZE) + (BLOCK_SIZE
				/ 2.0);
		game->player.y = (game->map_data.initial_y * BLOCK_SIZE) + (BLOCK_SIZE
				/ 2.0);
		if (cell == 'N')
			game->player.angle = 3 * PI / 2;
		else if (cell == 'S')
			game->player.angle = PI / 2;
		else if (cell == 'W')
			game->player.angle = PI;
		else if (cell == 'E')
			game->player.angle = 0;
		return ;
	}
}

void	init_player(t_game *game)
{
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.left_rotate = false;
	game->player.right_rotate = false;
	find_and_set_player_start(game);
}

void	init_game(t_game *game)
{
	game->map = game->map_data.map;
	game->map_height = game->map_data.map_size;
	if (game->map_height > 0 && game->map[0])
		game->map_width = ft_strlen(game->map[0]);
	else
		game->map_width = 0;
	init_player(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	load_textures(game);
	game->floor_color = rgb_to_int(game->map_data.c_rgb[0],
			game->map_data.c_rgb[1], game->map_data.c_rgb[2]);
	game->ceiling_color = rgb_to_int(game->map_data.f_rgb[0],
			game->map_data.f_rgb[1], game->map_data.f_rgb[2]);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	init_win(t_game *game)
{
	init_game(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, exit_program, game);
	mlx_loop_hook(game->mlx, render_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
