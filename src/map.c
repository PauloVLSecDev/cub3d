#include "../inc/cub3d.h"

void	valid_map(t_parse_map *data, char *first_line, int fd)
{
	//não utilizada?
	//int y;
	int size_map;
	char *current_line;

	//y = 0;
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