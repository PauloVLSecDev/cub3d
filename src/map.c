/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:37:50 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/11/08 17:45:13 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	get_largest_line(t_parse_map *data);
static void	convert_list_to_map(t_parse_map *data);
static char	**trim_map(char **map, int map_size);

static int	read_and_validate_line(t_parse_map *data, t_list **map_lines,
		int fd, int *map_ended)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	if (line_is_empty(line))
	{
		*map_ended = 1;
		free(line);
		return (1);
	}
	if (*map_ended == 1)
	{
		free(line);
		get_next_line(-1);
		free_list(map_lines);
		close_all();
		free_struct(data, "Error: Content found after map definition.\n");
		exit(1);
	}
	little_validade(data, line, map_lines);
	ft_lsadd_back(map_lines, create_node(line));
	free(line);
	return (1);
}

void	valid_map(t_parse_map *data, char *first_line, int fd)
{
	t_list	*map_lines;
	int		map_ended;

	map_lines = NULL;
	map_ended = 0;
	if (first_line)
		valid_first_line(data, first_line, &map_lines);
	while (read_and_validate_line(data, &map_lines, fd, &map_ended))
	{
	}
	if (!map_lines)
	{
		free_struct(data, "Error: No map found in file.\n");
		get_next_line(-1);
		close_all();
		exit(1);
	}
	data->list = map_lines;
	convert_list_to_map(data);
}

static void	convert_list_to_map(t_parse_map *data)
{
	char	**map_copy;
	char	**trimmed;

	map_size_list(data);
	get_largest_line(data);
	map_copy = duplicate_map(data);
	free_if_map_error(data, map_copy);
	find_player(map_copy, data, "NWES");
	if (!flood_fill(map_copy, data->initial_y, data->initial_x, data->map_size))
	{
		free_array(map_copy);
		get_next_line(-1);
		free_struct(data, "");
		exit(1);
	}
	trimmed = trim_map(map_copy, data->map_size);
	free_array(map_copy);
	closed_map(trimmed, data);
	data->map = trimmed;
	if (!data->map)
		free_struct(data, "error: in data->map");
	free_list(&data->list);
	return ;
}

static void	get_largest_line(t_parse_map *data)
{
	t_list	*tmp;
	int		size_line;
	int		current_len;

	tmp = data->list;
	size_line = 0;
	current_len = 0;
	while (tmp)
	{
		current_len = ft_strlen(tmp->line);
		if (current_len > size_line)
			size_line = current_len;
		tmp = tmp->next;
	}
	data->largest_line = size_line;
}

static char	**trim_map(char **map, int map_size)
{
	char	**validated_map;
	int		i;

	i = 0;
	validated_map = malloc(sizeof(char *) * (map_size + 1));
	if (!validated_map)
		return (NULL);
	while (map[i] != NULL)
	{
		validated_map[i] = ft_strtrim(map[i], " \t\n");
		i++;
	}
	validated_map[i] = NULL;
	return (validated_map);
}
