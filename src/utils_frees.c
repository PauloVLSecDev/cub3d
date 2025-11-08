/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_frees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:43:35 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/11/08 15:47:01 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	close_all(void)
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

void	valid_first_line(t_parse_map *data, char *first_line,
		t_list **map_lines)
{
	little_validade(data, first_line, map_lines);
	ft_lsadd_back(map_lines, create_node(first_line));
	free(first_line);
}

void	closed_map(char **map_copy, t_parse_map *data)
{
	int		x;
	int		y;

	y = 0;
	while (map_copy[y] != NULL)
	{
		x = 0;
		while (map_copy[y][x] != '\0')
		{
			if (ft_strchr("0NSEW", map_copy[y][x]))
			{
				free_array(map_copy);
				free_struct(data, "Error: Map  unreachable regions\n");
				get_next_line(-1);
				close_all();
				exit(1);
			}
			x++;
		}
		y++;
	}
	return ;
}

void	free_if_map_error(t_parse_map *data, char **map_copy)
{
	if (!map_copy)
	{
		free_struct(data, "");
		exit(1);
	}
	return ;
}
