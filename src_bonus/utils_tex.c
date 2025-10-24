/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:04:52 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/24 16:28:59 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	load_single_texture(t_game *game, t_tex *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		printf("Error: Could not load texture from path: %s\n", path);
		free_game_data(game);
		exit(1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
}

void	load_textures(t_game *game)
{
	load_single_texture(game, &game->textures[0], game->map_data.texture_no);
	load_single_texture(game, &game->textures[1], game->map_data.texture_so);
	load_single_texture(game, &game->textures[2], game->map_data.texture_we);
	load_single_texture(game, &game->textures[3], game->map_data.texture_ea);
}
