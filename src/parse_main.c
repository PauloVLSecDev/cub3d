


#include "../inc/cub3d.h" 

static int	process_parsing_line(char *line, int line_num,
 t_parse_map *data, int fd);

static int	process_parsing_line(char *line, int line_num,
 t_parse_map *data, int fd)
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

void	parse_map_file(int fd, t_parse_map *data)
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
		{
			free(line);
			return ;
		}
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
		printf("Error: map\n");
}

