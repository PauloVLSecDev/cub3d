/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:05:53 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/09/11 19:24:43 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	valid_map(int map);

int 	main(int argc, char *argv[])
{
	printf("executando a main \n");
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			printf("%s invalid file \n", argv[1]);
		else 
		{
			if (valid_map(fd) == 1)
				printf("valid\n");
			else
				printf("invald\n");
			//init_cub3d(fd);
		}
	}
	else
		printf("many arguments \n");
	return (0);
}

static int	valid_map(int map)
{
	char 	*line;
	int		player;

	player = 0;
	line  = get_next_line(map);
	while (line != NULL)
	{
		if (ft_strncmp(line, "N", ft_strlen(line)) == 0)
				player += 1;
		printf("%d \n", player);
		free(line);
		line = get_next_line(map);
	}
	return (player);
}
