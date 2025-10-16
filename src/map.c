#include "../inc/cub3d.h"

static void	free_map_on_error(char **map, int i)
{
	while (i > 0)
	{
		i--;
		free(map[i]);
	}
	free(map);
}

void	valid_map(t_parse_map *data, char *first_line, int fd)
{
	int		i;
	int		num_lines;
	char	*line;
	char	**temp_map;

	num_lines = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (!line_is_empty(line))
			num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	temp_map = malloc(sizeof(char *) * (num_lines + 1));
	if (!temp_map)
		return ;
	fd = open(data->file_path, O_RDONLY);
	i = 0;
	while (i < data->map_start_line - 1)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	temp_map[0] = ft_strtrim(first_line, " \t\n");
	i = 1;
	while (i < num_lines)
	{
		line = get_next_line(fd);
		if (!line_is_empty(line))
		{
			temp_map[i] = ft_strtrim(line, " \t\n");
			if (!temp_map[i])
			{
				free_map_on_error(temp_map, i);
				data->map = NULL;
				close(fd);
				free(line);
				return;
			}
			i++;
		}
		free(line);
	}
	temp_map[i] = NULL;
	data->map = temp_map;
	close(fd);
}
