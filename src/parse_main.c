/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:26:18 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/23 18:58:04 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	process_parsing_line(char *line, int line_num, t_parse_map *data,
				int fd);

static int	process_parsing_line(char *line, int line_num, t_parse_map *data,
		int fd)
{
	if (line_is_empty(line))
		return (-1);
	if (!all_configs_loaded(data))
	{
		parse_config_line(line, data);
		return (1);
	}
	else
	{
		if (data->map_start_line == -1)
		{
			data->map_start_line = line_num;
			valid_map(data, line, fd);
			return (0);
		}
	}
	return (1);
}

int	parse_map_file(int fd, t_parse_map *data)
{
	char	*line;
	int		line_num;
	int		status;

	line_num = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_num++;
		status = process_parsing_line(line, line_num, data, fd);
		if (status == 0)
			return (free(line), status);
		else if (status == -1)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!all_configs_loaded(data))
	{
		free_struct(data, "");
		return (status);
	}
	return (0);
}
