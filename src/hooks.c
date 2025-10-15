/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:21:17 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/15 21:33:25 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_program(t_game *game)
{
	free_game_data(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == ARROW_LEFT)
		game->player.left_rotate = true;
	if (keycode == ARROW_RIGHT)
		game->player.right_rotate = true;
	if (keycode == ESC)
		exit_program(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = false;
	if (keycode == S)
		game->player.key_down = false;
	if (keycode == A)
		game->player.key_left = false;
	if (keycode == D)
		game->player.key_right = false;
	if (keycode == ARROW_LEFT)
		game->player.left_rotate = false;
	if (keycode == ARROW_RIGHT)
		game->player.right_rotate = false;
	return (0);
}

void	move_player(t_player *player, char **map)
{
	float	angle_speed = 0.05;
	float	new_x;
	float	new_y;
	float	cos_angle;
	float	sin_angle;

	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	cos_angle = cos(player->angle) * MOVE_SPEED;
	sin_angle = sin(player->angle) * MOVE_SPEED;
	new_x = player->x;
	new_y = player->y;
	if (player->key_up)
	{
		new_x += cos_angle;
		new_y += sin_angle;
	}
	if (player->key_down)
	{
		new_x -= cos_angle;
		new_y -= sin_angle;
	}
	if (player->key_left)
	{
		new_x += sin_angle;
		new_y -= cos_angle;
	}
	if (player->key_right)
	{
		new_x -= sin_angle;
		new_y += cos_angle;
	}
	if (map[(int)(new_y / BLOCK_SIZE)][(int)(new_x / BLOCK_SIZE)] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
}
