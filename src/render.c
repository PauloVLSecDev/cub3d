/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:49:56 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/15 21:38:31 by yurivieirad      ###   ########.fr       */
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

void	draw_filled_square(int x, int y, int size, int color, t_game *game)
{
	int	i;
	int	j;

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
}

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

void	perform_dda(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= game->map_height || \
			ray->map_x < 0 || ray->map_x >= game->map_width)
		{
			ray->hit = 1;
		}
		else if (game->map[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1;
		}
	}
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;
	int	tex_y;

	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(x, y, game->ceiling_color, game);
		y++;
	}
	while (y < ray->draw_end)
	{
		tex_y = (int)((y - ray->draw_start)
				* game->textures[ray->side].height / ray->line_height);
		color = *(int *)(game->textures[ray->side].addr
				+ (tex_y * game->textures[ray->side].line_len + ray->tex_x
					* (game->textures[ray->side].bpp / 8)));
		put_pixel(x, y, color, game);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		put_pixel(x, y, game->floor_color, game);
		y++;
	}
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
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.map_x - game->player.x / BLOCK_SIZE + (1 - ray.step_x) / 2) / ray.ray_dir_x;
		else
			ray.perp_wall_dist = (ray.map_y - game->player.y / BLOCK_SIZE + (1 - ray.step_y) / 2) / ray.ray_dir_y;
		ray.line_height = (int)(WIN_HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + WIN_HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + WIN_HEIGHT / 2;
		if (ray.draw_end >= WIN_HEIGHT)
			ray.draw_end = WIN_HEIGHT - 1;
		if (ray.side == 0)
			ray.wall_x = game->player.y / BLOCK_SIZE + ray.perp_wall_dist * ray.ray_dir_y;
		else
			ray.wall_x = game->player.x / BLOCK_SIZE + ray.perp_wall_dist * ray.ray_dir_x;
		ray.wall_x -= floor(ray.wall_x);
		ray.tex_x = (int)(ray.wall_x * (double)game->textures[ray.side].width);
		if (ray.side == 0 && ray.ray_dir_x > 0)
			ray.tex_x = game->textures[ray.side].width - ray.tex_x - 1;
		if (ray.side == 1 && ray.ray_dir_y < 0)
			ray.tex_x = game->textures[ray.side].width - ray.tex_x - 1;
		draw_vertical_line(game, &ray, x);
		x++;
	}
}

void	draw_minimap(t_game *game)
{
	int	y;
	int	x;
	int	mini_block_size;

	y = 0;
	mini_block_size = BLOCK_SIZE / 4;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_filled_square(x * mini_block_size, y * mini_block_size, mini_block_size, 0x808080, game);
			else if (game->map[y][x] == '0')
				draw_filled_square(x * mini_block_size, y * mini_block_size, mini_block_size, 0xC0C0C0, game);
			x++;
		}
		y++;
	}
}

void	draw_player_minimap(t_game *game)
{
	int mini_player_size = PLAYER_SIZE / 4;
	draw_filled_square(game->player.x / 4 - mini_player_size / 2, game->player.y / 4 - mini_player_size / 2, mini_player_size, 0xFF0000, game);
}

int	render_loop(t_game *game)
{
	move_player(&game->player, game->map_data.map);
	raycasting(game);
	draw_minimap(game);
	draw_player_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
