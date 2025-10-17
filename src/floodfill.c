/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:45:11 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/17 16:54:47 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
int	flood_fill(char **map_copy, int player_y, int player_x, t_parse_data *data)
{
	int map_height;
	inty map_width;

	map_height = map_size_list(data);
	map_width = data->largest_line;

	map_copy[initial_y][initial_x]	
}
*/

void	find_player(char **map_copy, t_parse_map *data, char *char_player) 
{
	int count_player;
	int x;
	int y;

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
	if (count_player != 1)
	{
		printf("error \n"); 
		free_array(map_copy);			
		exit(1);
	}
}





