/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:09:09 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/10/09 22:12:14 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
bool	line_is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void init_data(t_parse_map *data)
{
	data->num_lines = 0;
	data->Texture_NO = NULL;
	data->Texture_SO = NULL;
	data->Texture_WE = NULL;
	data->Texture_EA = NULL;
	data->F_rgb[0] = -1;
	data->C_rgb[0] = -1;
	data->map_start_line = -1;
	data->map = NULL;

}

void	parse_map_file(int fd, t_parse_map *data)
{
	char	*line;
	int		line_num;

	line_num = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_num++;
		if (line_is_empty(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (!all_configs_loaded(data))
			parse_config_line(line, data);
		else
		{
			if (data->map_start_line == -1)
			{
				data->map_start_line = line_num;
				valid_map(data, line, fd);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!all_configs_loaded(data))
		printf("Error: map\n");
}

int	main(int argc, char *argv[])
{
	t_parse_map	*data;
	int	fd;

	data = malloc(sizeof(t_parse_map));
	if (argc == 2)
	{
		if (!extencion_map(argv[1]))
				printf("invalid extension");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			printf("%s invalid file \n", argv[1]);
		else
		{
			init_data(data);
			/*parse_map_file(fd, data);
			printf("%i textura valida \n", data->W_texture);
			printf("linha onde o map comeca %i \n", data->map_start_line);
			printf("%s textura NO \n", data->Texture_NO);
			printf("%s textura SO \n", data->Texture_SO);
			printf("%s textura WE \n", data->Texture_WE);
			printf("%s textura EA \n", data->Texture_EA);
			printf("teto R %i G %i B %i \n", data->C_rgb[0], data->C_rgb[1], data->C_rgb[2]);
			printf("chao R %i G %i B %i \n", data->F_rgb[0], data->F_rgb[1], data->F_rgb[2]);*/
		}
	}
	else
	{
		printf("Arguments Error: insert: ./map map_name.cub\n");
		exit(1);
	}
	init_win();

	return (0);
}
