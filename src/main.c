/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:09:09 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/09/15 01:38:56 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000000000001";
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

int	key_press_handler(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->y -= MOVE_SPEED;
	else if (keycode == KEY_S)
		player->y += MOVE_SPEED;
	else if (keycode == KEY_A)
		player->x -= MOVE_SPEED;
	else if (keycode == KEY_D)
		player->x += MOVE_SPEED;
	else if (keycode == KEY_ESC)
		exit_program(player);
	return (0);
}

int	render_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);

	mlx_pixel_put(game->mlx, game->win, game->pixel_x,
		game->pixel_y, PIXEL_COLOR);

	return (0);
}


void	init_player(t_player *player)
{
	player.x = WIN_WIDTH / 2;
	player.y = WIN_HEIGHT / 2;

}

void	init_game(t_game *game)
{
	init_player(&game->player);
	game->map = get_map();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Game");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	main(void)
{
	t_game		game;
	t_player	player;

	game.mlx = mlx_init();

	game.win = mlx_new_window(game.mlx, WIN_WIDTH,
			WIN_HEIGHT, "CUB 3D");
	init_player(&player);
	mlx_key_hook(game.win, key_press_handler, &game);
	mlx_hook(game.win, 17, 0, exit_program, &game);
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
}
