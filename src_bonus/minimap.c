/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:57:55 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/26 13:50:53 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	draw_minimap_tile(t_game *game, t_point screen_pos)
{
	int	map_y;
	int	map_x;

	map_y = game->minimap.map_start_y + (screen_pos.y
			/ game->minimap.mini_block_size);
	map_x = game->minimap.map_start_x + (screen_pos.x
			/ game->minimap.mini_block_size);
	if (map_y >= 0 && map_y < game->map_height && map_x >= 0
		&& map_x < game->map_width)
	{
		if (game->map[map_y][map_x] == '1')
			draw_filled_square(screen_pos, game->minimap.mini_block_size,
				0x808080, game);
		else if (game->map[map_y][map_x] == 'F')
			draw_filled_square(screen_pos, game->minimap.mini_block_size,
				0xC0C0C0, game);
		else
			draw_filled_square(screen_pos, game->minimap.mini_block_size,
				0x000000, game);
	}
	else
		draw_filled_square(screen_pos, game->minimap.mini_block_size, 0x303030,
			game);
}

void	draw_minimap(t_game *game)
{
	t_point	screen_pos;

	game->minimap.mini_block_size = BLOCK_SIZE / 4;
	game->minimap.player_map_x = game->player.x / BLOCK_SIZE;
	game->minimap.player_map_y = game->player.y / BLOCK_SIZE;
	game->minimap.map_start_y = game->minimap.player_map_y
		- (MINIMAP_VIEW_HEIGHT / 2);
	game->minimap.map_start_x = game->minimap.player_map_x - (MINIMAP_VIEW_WIDTH
			/ 2);
	screen_pos.y = 0;
	while (screen_pos.y < (MINIMAP_VIEW_HEIGHT * game->minimap.mini_block_size))
	{
		screen_pos.x = 0;
		while (screen_pos.x < (MINIMAP_VIEW_WIDTH
				* game->minimap.mini_block_size))
		{
			draw_minimap_tile(game, screen_pos);
			screen_pos.x += game->minimap.mini_block_size;
		}
		screen_pos.y += game->minimap.mini_block_size;
	}
}

void	draw_player_minimap(t_game *game)
{
	t_point	player_pos;
	int		mini_player_size;
	int		mini_block_size;

	mini_player_size = PLAYER_SIZE / 4;
	mini_block_size = BLOCK_SIZE / 4;
	player_pos.x = (MINIMAP_VIEW_WIDTH * mini_block_size) / 2;
	player_pos.y = (MINIMAP_VIEW_HEIGHT * mini_block_size) / 2;
	player_pos.x -= mini_player_size / 2;
	player_pos.y -= mini_player_size / 2;
	draw_filled_square(player_pos, mini_player_size, 0xFF0000, game);
}
