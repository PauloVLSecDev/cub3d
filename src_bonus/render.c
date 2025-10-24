/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:49:56 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/23 20:59:33 by pvitor-l         ###   ########.fr       */
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

void	draw_filled_square(t_point start, int size, int color, t_game *game)
{
	t_point	p;

	p.y = 0;
	while (p.y < size)
	{
		p.x = 0;
		while (p.x < size)
		{
			put_pixel(start.x + p.x, start.y + p.y, color, game);
			p.x++;
		}
		p.y++;
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
		if (ray->map_y < 0 || ray->map_y >= game->map_height || ray->map_x < 0
			|| ray->map_x >= game->map_width)
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
	int		y;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		color;

	y = 0;
	while (y < ray->draw_start)
		put_pixel(x, y++, game->ceiling_color, game);
	step = 1.0 * game->textures[ray->side].height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color = *(int *)(game->textures[ray->side].addr + (tex_y
					* game->textures[ray->side].line_len + ray->tex_x
					* (game->textures[ray->side].bpp / 8)));
		put_pixel(x, y, color, game);
		y++;
	}
	while (y < WIN_HEIGHT)
		put_pixel(x, y++, game->floor_color, game);
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
