/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:58:08 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/17 21:28:51 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_size_list(t_parse_map *data)
{
	int		map_size;
	t_list	*map;

	map_size = 0;
	map = data->list;
	while (map)
	{
		if (!line_is_empty(map->line))
			map_size++;
		map = map->next;
	}
	data->map_size = map_size;
}

void	little_validade(t_parse_map *data, char *current_line)
{
	if (!is_valid_map_line(current_line))
	{
		free_struct(data, "line invalid");
		exit(1);
	}
}

char	**duplicate_map(t_parse_map *data)
{
	t_list	*tmp;
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (data->map_size + 1));
	i = 0;
	if (!map)
		return (NULL);
	tmp = data->list;
	while (tmp)
	{
		if (tmp->line)
			map[i] = ft_strdup(tmp->line);
		else
		{
			free_array(map);
			return (NULL);
		}
		i++;
		tmp = tmp->next;
	}
	map[i] = NULL;
	return (map);
}
