/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:37:50 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/07 17:40:44 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	valid_map(t_parse_map *data, char *first_line, int fd)
{
	int y;	
	int size_map;
	char *current_line;

	y = 0;
	size_map = 1;

	printf("debug: %s \n", first_line);
	current_line = first_line;
	while (current_line)
	{
			if (line_is_empty(current_line))
			{
				free(current_line);		
				current_line = get_next_line(fd);
					continue ;
			}
			printf("debug: %s \n", current_line);
			free(current_line);
			current_line = get_next_line(fd);
			size_map++;
	}
	data->map = malloc(sizeof(char *) * size_map);
	printf("debug: o mapa tem %i linhas \n", size_map);
}
