/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:09:41 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/21 18:53:11 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x / BLOCK_SIZE - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x / BLOCK_SIZE)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y / BLOCK_SIZE - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y / BLOCK_SIZE)
			* ray->delta_dist_y;
	}
}

static void	handle_rotation(t_player *player)
{
	float	angle_speed;

	angle_speed = 0.05;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
}

static void	get_movement_vector(t_player *player, float *move_x, float *move_y)
{
	int		forward_dir;
	int		strafe_dir;
	float	cos_angle;
	float	sin_angle;

	forward_dir = player->key_up - player->key_down;
	strafe_dir = player->key_left - player->key_right;
	cos_angle = cos(player->angle) * MOVE_SPEED;
	sin_angle = sin(player->angle) * MOVE_SPEED;
	*move_x = (forward_dir * cos_angle) + (strafe_dir * sin_angle);
	*move_y = (forward_dir * sin_angle) - (strafe_dir * cos_angle);
}

static void	calculate_new_position(t_player *player, float *new_x, float *new_y)
{
	float	move_x;
	float	move_y;

	get_movement_vector(player, &move_x, &move_y);
	*new_x = player->x + move_x;
	*new_y = player->y + move_y;
}

void	move_player(t_player *player, char **map)
{
	float	new_x;
	float	new_y;

	handle_rotation(player);
	calculate_new_position(player, &new_x, &new_y);
	if (map[(int)(new_y / BLOCK_SIZE)][(int)(new_x / BLOCK_SIZE)] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
}
