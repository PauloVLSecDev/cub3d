/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:21:35 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/09/18 20:36:36 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(x, y, 0x202020, game); // Fundo cinza escuro
			x++;
		}
		y++;
	}
}

void	draw_filled_square(int x, int y, int size, int color, t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(x + j, y + i, color, game);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_filled_square(x * BLOCK_SIZE, y * BLOCK_SIZE,
					BLOCK_SIZE, 0xeeeeee, game);
			else if (map[y][x] == '0')
				draw_filled_square(x * BLOCK_SIZE, y * BLOCK_SIZE,
					BLOCK_SIZE, 0x404040, game);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	draw_filled_square(game->player.x - PLAYER_SIZE / 2,
		game->player.y - PLAYER_SIZE / 2, PLAYER_SIZE, 0xFF0000, game);
	float line_length = 20.0;
	float end_x = game->player.x + line_length * cos(game->player.angle);
	float end_y = game->player.y + line_length * sin(game->player.angle);
	float dx = end_x - game->player.x;
	float dy = end_y - game->player.y;
	int steps = fmax(fabs(dx), fabs(dy));
	float x_inc = dx / (float)steps;
	float y_inc = dy / (float)steps;
	float x = game->player.x;
	float y = game->player.y;
	for (int i = 0; i <= steps; i++)
	{
		put_pixel(round(x), round(y), 0xFF0000, game);
		x += x_inc;
		y += y_inc;
	}
}

int	render_loop(t_game *game)
{
	move_player(&game->player, game->map);
	clear_image(game);
	draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}