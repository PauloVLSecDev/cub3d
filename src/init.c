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

static void	find_and_set_player_start(t_game *game)
{
	int		y;
	int		x;
	char	cell;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			cell = game->map[y][x];
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			{
				game->player.x = (x * BLOCK_SIZE) + (BLOCK_SIZE / 2.0);
				game->player.y = (y * BLOCK_SIZE) + (BLOCK_SIZE / 2.0);
				if (cell == 'N')
					game->player.angle = 3 * PI / 2;
				else if (cell == 'S')
					game->player.angle = PI / 2;
				else if (cell == 'W')
					game->player.angle = PI;
				else if (cell == 'E')
					game->player.angle = 0;
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	printf("Error\n: Player starting position not found in map!\n");
	exit(1);
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
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx, game->map_data.Texture_NO,
			&game->textures[0].width, &game->textures[0].height);
	if (!game->textures[0].img)
	{
		printf("Error: Could not load texture NO\n");
		exit(1);
	}
	game->textures[0].addr = mlx_get_data_addr(game->textures[0].img, &game->textures[0].bpp,
			&game->textures[0].line_len, &game->textures[0].endian);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx, game->map_data.Texture_SO,
			&game->textures[1].width, &game->textures[1].height);
	if (!game->textures[1].img)
	{
		printf("Error: Could not load texture SO\n");
		exit(1);
	}
	game->textures[1].addr = mlx_get_data_addr(game->textures[1].img, &game->textures[1].bpp,
			&game->textures[1].line_len, &game->textures[1].endian);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx, game->map_data.Texture_WE,
			&game->textures[2].width, &game->textures[2].height);
	if (!game->textures[2].img)
	{
		printf("Error: Could not load texture WE\n");
		exit(1);
	}
	game->textures[2].addr = mlx_get_data_addr(game->textures[2].img, &game->textures[2].bpp,
			&game->textures[2].line_len, &game->textures[2].endian);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx, game->map_data.Texture_EA,
			&game->textures[3].width, &game->textures[3].height);
	if (!game->textures[3].img)
	{
		printf("Error: Could not load texture EA\n");
		exit(1);
	}
	game->textures[3].addr = mlx_get_data_addr(game->textures[3].img, &game->textures[3].bpp,
			&game->textures[3].line_len, &game->textures[3].endian);
}

void	init_game(t_game *game)
{
	game->map = game->map_data.map;
	game->map_height = 0;
	if (game->map)
	{
		while (game->map[game->map_height])
			game->map_height++;
	}
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
	game->floor_color = rgb_to_int(game->map_data.C_rgb[0], \
	game->map_data.C_rgb[1], game->map_data.C_rgb[2]);
	game->ceiling_color = rgb_to_int(game->map_data.F_rgb[0], \
	game->map_data.F_rgb[1], game->map_data.F_rgb[2]);
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