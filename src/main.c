/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:05:53 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/01 17:08:05 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_lines(char *path)
{
	int	count_lines; 
	char *line;

	int map;

	map = open(path, O_RDONLY);
	
	count_lines = 0;
	line = get_next_line(map);
	while (line != NULL)
	{
		if (!line_is_empty(line))
				count_lines++;
		free(line);
		line = get_next_line(map);
	}
	close(map);
	return (count_lines);
}

t_parse_map	*storege_map(int	map, char	*path)
{
	char	*line;
	int		i;
	int		player;
	t_parse_map	**data;

	player = 0;
	i = 0;
	data = malloc(sizeof(t_parse_map));
	(*data)->num_lines = (count_lines(path) + 1);
	printf("%i numeros de linhas do arquivo \n", (*data)->num_lines);
	(*data)->map = (char **)malloc(sizeof(char *) * (*data)->num_lines);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (valid_line(line, data))
			(*data)->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(map);
		i++;
	}
	return (*data);
}

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

int	main(int argc, char *argv[])
{
	t_parse_map	**data;
	int	fd;

	data = NULL;
	if (argc == 2)
	{
		if (!extencion_map(argv[1]))
			printf("invalid extension\n");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			printf("%s invalid file \n", argv[1]);
		else 
		{
			*(data) = storege_map(fd, argv[1]);
		}
	}
	else
		printf("many arguments \n");
	return (0);
}


