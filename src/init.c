/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* init.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/09/18 17:20:27 by yurivieirad       #+#    #+#             */
/* Updated: 2025/09/18 22:37:35 by yurivieirad      ###   ########.fr       */
/* */
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
	map[1] = "100010000010001";
	map[2] = "100000000000001";
	map[3] = "100000100000001";
	map[4] = "100000000000001";
	map[5] = "100000000000001";
	map[6] = "100001000000001";
	map[7] = "100000000000101";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = NULL;
	return (map);
}

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	char *path = "texture/open.xpm";
	while (i < 4)
	{
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx, path,
				&game->textures[i].width, &game->textures[i].height);
		if (!game->textures[i].img)
		{
			printf("Error: Texture not found\n");
			exit(1);
		}
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bpp, &game->textures[i].line_len,
				&game->textures[i].endian);
		i++;
	}
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
	load_textures(game);
	game->floor_color = 0x404040;
	game->ceiling_color = 0x87CEEB;
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	init_win(void)
{
	t_game	game;

	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, exit_program, &game);
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}