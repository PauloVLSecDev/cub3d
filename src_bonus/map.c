/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:37:50 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/21 18:53:01 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	get_largest_line(t_parse_map *data);
static void	convert_list_to_map(t_parse_map *data);
static char	**trim_map(char **map, int map_size);

void	valid_map(t_parse_map *data, char *first_line, int fd)
{
	t_list	*map_lines;
	char	*current_line;

	map_lines = NULL;
	if (first_line)
	{
		little_validade(data, first_line);
		ft_lsadd_back(&map_lines, create_node(first_line));
	}
	while (true)
	{
		current_line = get_next_line(fd);
		if (!current_line)
			break ;
		if (line_is_empty(current_line))
		{
			free(current_line);
			break ;
		}
		little_validade(data, current_line);
		ft_lsadd_back(&map_lines, create_node(current_line));
		free(current_line);
	}
	data->list = map_lines;
	convert_list_to_map(data);
}

static void	convert_list_to_map(t_parse_map *data)
{
	char	**map_copy;

	map_size_list(data);
	get_largest_line(data);
	map_copy = duplicate_map(data);
	if (!map_copy)
	{
		free_struct(data, "");
		exit(1);
	}
	find_player(map_copy, data, "NWES");
	if (!flood_fill(map_copy, data->initial_y, data->initial_x, data->map_size))
	{
		free_array(map_copy);
		free_struct(data, "");
		exit(1);
	}
	data->map = trim_map(map_copy, data->map_size);
	if (!data->map)
		free_struct(data, "error: in data->map");
	free_array(map_copy);
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
		validated_map[i] = ft_strtrim(map[i], " \t");
		i++;
	}
	validated_map[i] = NULL;
	return (validated_map);
}
