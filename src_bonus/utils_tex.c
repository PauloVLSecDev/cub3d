/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:04:52 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/26 13:51:15 by yvieira-         ###   ########.fr       */
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

int	validate_texture_extension(const char *filename)
{
	const char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".xpm", ft_strlen(extension)) != 0)
	{
		printf("Erro: Texture extension '%s' .xpm \n", filename);
		return (0);
	}
	return (1);
}

int	validate_textures(t_game *game)
{
	if (!validate_texture_extension(game->map_data.texture_no)
		|| !validate_texture_extension(game->map_data.texture_so)
		|| !validate_texture_extension(game->map_data.texture_ea)
		|| !validate_texture_extension(game->map_data.texture_we))
	{
		return (1);
	}
	return (0);
}
