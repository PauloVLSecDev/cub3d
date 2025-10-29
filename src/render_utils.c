/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:46:23 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/26 17:57:35 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_player *player, int x)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = cos(player->angle);
	dir_y = sin(player->angle);
	plane_x = -dir_y;
	plane_y = dir_x;
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = dir_x + plane_x * FOV * ray->camera_x;
	ray->ray_dir_y = dir_y + plane_y * FOV * ray->camera_x;
	ray->map_x = (int)(player->x / BLOCK_SIZE);
	ray->map_y = (int)(player->y / BLOCK_SIZE);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	ray->side = 0;
	ray->tex_id = 0;
}

static void	calculate_wall_projection(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.x / BLOCK_SIZE + (1
					- ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.y / BLOCK_SIZE + (1
					- ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static void	calculate_texture_x(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->wall_x = game->player.y / BLOCK_SIZE + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		ray->wall_x = game->player.x / BLOCK_SIZE + ray->perp_wall_dist
			* ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)game->textures[ray->tex_id].width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = game->textures[ray->tex_id].width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = game->textures[ray->tex_id].width - ray->tex_x - 1;
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, &game->player, x);
		calculate_step_and_side_dist(&ray, &game->player);
		perform_dda(&ray, game);
		calculate_wall_projection(&ray, game);
		calculate_texture_x(&ray, game);
		draw_vertical_line(game, &ray, x);
		x++;
	}
}
