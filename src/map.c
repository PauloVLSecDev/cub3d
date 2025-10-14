/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:37:50 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/14 20:07:31 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void little_validade(char *current_line);

static t_list	*create_node(void)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);	
	new->line = NULL;
	new->next = NULL;
	return (new);
}

static void show_list(t_parse_map *data)
{
	int size_map;

	size_map = 0;	
	t_list *map;
	map = data->list;
	while (map)
	{
		if (!line_is_empty(map->line))
		{
			printf("%s\n", map->line);
			printf("size map is %i\n", size_map);
			size_map++;
		}
		map = map->next;	
	}
}

static void little_validade( char *current_line)  
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
	t_list *tmp;
	char *current_line;

	tmp = data->list;
	current_line = first_line;
	tmp->line = ft_strdup(current_line);
	while (current_line)
	{
		little_validade(current_line);
		if (line_is_empty(current_line))
		{
			free(current_line);
			current_line = get_next_line(fd);
			continue ;
		}
		tmp->next = create_node();
		tmp = tmp->next; 
		tmp->line = ft_strdup(current_line); 
		free(current_line);
		current_line = get_next_line(fd);
		if (!current_line)
		{
			// free_list	
			// break ;
		}
	}
	show_list(data);
}
