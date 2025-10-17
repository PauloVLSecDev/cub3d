/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:37:50 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/17 16:55:13 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void		little_validade(char *current_line);
static int		map_size_list(t_parse_map *data);
static t_list	*create_node(char *content);
static void		ft_lsadd_back(t_list **head, t_list *new);
static void		get_largest_line(t_parse_map *data);
static void		convert_list_to_map(t_parse_map *data);
static char		**duplicate_map(t_parse_map *data);
static char		**trim_map(char **map, int map_size);

static t_list	*create_node(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = ft_strdup(content);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

static void	ft_lsadd_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

static int	map_size_list(t_parse_map *data)
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
	return (map_size);
}

static void	little_validade(char *current_line)
{
	if (!is_valid_map_line(current_line))
	{
		//	free_all_list
		printf("erro line invalid %s\n", current_line);
		exit(1);
	}
}

void	valid_map(t_parse_map *data, char *first_line, int fd)
{
	t_list	*map_lines;
	char	*current_line;

	map_lines = NULL;
	if (first_line)
	{
		little_validade(first_line);
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
		little_validade(current_line);
		ft_lsadd_back(&map_lines, create_node(current_line));
		free(current_line);
	}
	data->list = map_lines;
	convert_list_to_map(data);
}

static void	convert_list_to_map(t_parse_map *data)
{
	int	map_size;
	char **map_copy;

	get_largest_line(data);
	map_copy = duplicate_map(data);
	if (!map_copy)
	{
		//free_struct(data);
		exit(1);
	}
	find_player(map_copy, data, "NWES");
//    if (!flood_fll(map_copy, 0, 0, data);
//    {
	//  free_array(map_copy);
	//      free_struct(data);
	//  printf("error: flood fill\n");
	//  exit(1);
//  }
	map_size = map_size_list(data);
	data->map = trim_map(map_copy, map_size);
	if (!data->map)
	{
		// clean_all(
	}
	free_array(map_copy);
	return ;
}

static char	**duplicate_map(t_parse_map *data)
{
	t_list	*tmp;
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (map_size_list(data) + 1));
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
