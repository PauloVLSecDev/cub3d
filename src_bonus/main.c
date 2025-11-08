/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:55:12 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/11/08 15:52:33 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	init_main(int fd, char *filename, t_game *game)
{
	if (!extencion_map(filename))
	{
		printf("invalid extensio\n");
		return ;
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		printf("%s invalid file \n", filename);
	else
	{
		init_data(&game->map_data);
		game->map_data.file_path = filename;
		if (parse_map_file(fd, &game->map_data) == 0)
			init_win(game);
		else
		{
			close(fd);
			free_struct(&game->map_data, "");
		}
		get_next_line(-1);
	}
}

int	is_valid_map_line(char *line)
{
	char	*valid_chars;
	int		i;

	if (!line)
		return (0);
	valid_chars = " \t01NSWE";
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (ft_strchr(valid_chars, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

bool	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void	init_data(t_parse_map *data)
{
	data->list = NULL;
	data->initial_y = 0;
	data->initial_x = 0;
	data->num_lines = 0;
	data->texture_no = NULL;
	data->texture_so = NULL;
	data->texture_we = NULL;
	data->texture_ea = NULL;
	data->f_rgb[0] = -1;
	data->c_rgb[0] = -1;
	data->map_size = 0;
	data->map_start_line = -1;
	data->map = NULL;
	data->file_path = NULL;
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	fd = 0;
	ft_bzero(&game, sizeof(t_game));
	if (argc == 2)
		init_main(fd, argv[1], &game);
	else
		printf("Arguments Error: insert: maps/map_name.cub\n");
	free_game_data(&game);
	return (0);
}
