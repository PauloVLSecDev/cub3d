/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:20:27 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/09/18 20:35:40 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_player(t_player *player)
{
	player->x = 1.5 * BLOCK_SIZE;
	player->y = 1.5 * BLOCK_SIZE;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100010000000001";
	map[2] = "100000000000001";
	map[3] = "100000100000001";
	map[4] = "100000000000001";
	map[5] = "100000010000001";
	map[6] = "100001000000001";
	map[7] = "100000000000001";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = NULL;
	return (map);
}

void	init_game(t_game *game)
{
	init_player(&game->player);
	game->map = get_map();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}