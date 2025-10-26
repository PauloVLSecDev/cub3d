/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:20:37 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/26 13:51:17 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game_data(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_textures(&game->map_data);
	free_map(game->map_data.map);
	close_all();
}

void	trim_newline(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

int	extencion_map(char *filename)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	if (filename[i] == '.')
		return (valid);
	while (filename[i] != '\0' && valid == 0)
	{
		if ((filename[i] == '.' && filename[i + 1] == 'c') && (filename
				[i + 2] == 'u' && filename[i + 3] == 'b') && (filename
				[i + 4] == '\0'))
			valid += 1;
		i++;
	}
	return (valid);
}

int	num_player(char *line)
{
	int	i;
	int	count_player;

	i = 0;
	count_player = 0;
	while (line[i] || line[i] != '\n')
	{
		if (!ft_isalpha(line[i]) && line[i + 1] == P_SOUTH && !ft_isalpha(line
				[i + 2]))
			return (count_player += 1);
		else if (!ft_isalpha(line[i]) && line[i + 1] == P_NORTH
			&& !ft_isalpha(line[i + 2]))
			return (count_player += 1);
		else if (!ft_isalpha(line[i]) && line[i + 1] == P_WEST
			&& !ft_isalpha(line[i + 2]))
			return (count_player += 1);
		else if (!ft_isalpha(line[i]) && line[i + 1] == P_EASTH
			&& !ft_isalpha(line[i + 2]))
			return (count_player += 1);
		else
			i++;
	}
	return (count_player);
}
