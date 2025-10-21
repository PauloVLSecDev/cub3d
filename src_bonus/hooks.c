/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:21:17 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/21 18:52:45 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	exit_program(t_game *game)
{
	free_game_data(game);
	exit(0);
	return (0);
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
