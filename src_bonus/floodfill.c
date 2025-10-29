/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:45:11 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/29 21:47:29 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	only_one_player(char **map_copy, t_parse_map *data,
				int count_player);

int	flood_fill(char **map_copy, int y, int x, int map_height)
{
	if (y < 0 || y >= map_height || x < 0 || x >= (int)ft_strlen(map_copy[y]))
	{
		printf("possicion player invalid");
		return (0);
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return (1);
	if (map_copy[y][x] == ' ' || map_copy[y][x] == '\t')
	{
		printf("error map: space found at %d,%d\n", y, x);
		return (0);
	}
	map_copy[y][x] = 'F';
	if (flood_fill(map_copy, y, x + 1, map_height) == 0)
		return (0);
	if (flood_fill(map_copy, y, x - 1, map_height) == 0)
		return (0);
	if (flood_fill(map_copy, y + 1, x, map_height) == 0)
		return (0);
	if (flood_fill(map_copy, y - 1, x, map_height) == 0)
		return (0);
	return (1);
}

void	find_player(char **map_copy, t_parse_map *data, char *char_player)
{
	int	count_player;
	int	x;
	int	y;

	y = 0;
	count_player = 0;
	while (map_copy[y] != NULL)
	{
		x = 0;
		while (map_copy[y][x] != '\0')
		{
			if (ft_strchr(char_player, map_copy[y][x]))
			{
				data->vision_player = map_copy[y][x];
				data->initial_y = (float)y;
				data->initial_x = (float)x;
				count_player++;
			}
			x++;
		}
		y++;
	}
	only_one_player(map_copy, data, count_player);
}

static void	only_one_player(char **map_copy, t_parse_map *data,
		int count_player)
{
	if (count_player != 1)
	{
		printf("error many players\n");
		free_array(map_copy);
		free_struct(data, "");
		get_next_line(-1);
		close_all();
		exit(1);
	}
}
