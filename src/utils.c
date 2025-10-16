
#include "../inc/cub3d.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game_data(t_game *game)
{
	free(game->map_data.Texture_NO);
	free(game->map_data.Texture_SO);
	free(game->map_data.Texture_WE);
	free(game->map_data.Texture_EA);
	free_map(game->map_data.map);
}

void	trim_newline(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

int	all_configs_loaded(t_parse_map *data)
{
	if (data->Texture_NO && data->Texture_SO && data->Texture_WE
		&& data->Texture_EA && data->F_rgb[0] != -1 && data->C_rgb[0] != -1)
		return (1);
	return (0);
}

void	parse_config_line(char *line, t_parse_map *data)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0])
	{
		if (tokens)
			free_array(tokens);
		return ;
	}
	if (tokens[1])
	{
		trim_newline(tokens[1]);
	}
	if (ft_strncmp(tokens[0], "NO", 3) == 0 && !data->Texture_NO)
		data->Texture_NO = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0 && !data->Texture_SO)
		data->Texture_SO = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0 && !data->Texture_WE)
		data->Texture_WE = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0 && !data->Texture_EA)
		data->Texture_EA = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "F", 2) == 0 && data->F_rgb[0] == -1)
		parse_colors(tokens[1], data->F_rgb);
	else if (ft_strncmp(tokens[0], "C", 2) == 0 && data->C_rgb[0] == -1)
		parse_colors(tokens[1], data->C_rgb);
	else
	{
		if (!all_configs_loaded(data))
			printf("Erro: Linha de configuração inválida: %s\n", line);
	}
	free_array(tokens);
}

void	parse_colors(char *rgb_str, int *color_array)
{
	char	**rgb_val;
	int		i;

	rgb_val = ft_split(rgb_str, ',');
	if (!rgb_val || !rgb_val[0] || !rgb_val[1] || !rgb_val[2] || rgb_val[3])
	{
		printf("Erro: Formato de cor RGB inválido.\n");
		if (rgb_val)
			free_array(rgb_val);
		return ;
	}
	i = 0;
	while (i < 3)
	{
		color_array[i] = ft_atoi(rgb_val[i]);
		if (color_array[i] < 0 || color_array[i] > 255)
		{
			printf("Error: color value valid is 0-255.\n");
			color_array[0] = -1;
			break ;
		}
		i++;
	}
	free_array(rgb_val);
}
