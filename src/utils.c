
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

int	extencion_map(char *filename)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	if (filename[i] == '.')
		return (valid);
	while (filename[i] != '\0' && valid == 0)
	{
		if ((filename[i] == '.' && filename[i + 1] == 'c') && (filename[i
				+ 2] == 'u' && filename[i + 3] == 'b') && (filename[i
				+ 4] == '\0'))
		{
			valid += 1;
			printf("extencaio map is valid\n");
		}
		i++;
	}
	return (valid);
}

int	num_player(char *line)
{
	int i;
	int count_player;

	i = 0;
	count_player = 0;
	while (line[i] || line[i] != '\n')
	{
		if (!ft_isalpha(line[i]) && line[i + 1] == P_SOUTH && !ft_isalpha(line[i
				+ 2]))
			return (count_player += 1);
		else if (!ft_isalpha(line[i]) && line[i + 1] == P_NORTH
			&& !ft_isalpha(line[i + 2]))
			return (count_player += 1);
		else if (!ft_isalpha(line[i]) && line[i + 1] == P_WEST
			&& !ft_isalpha(line[i + 2]))
			return (count_player += 1);
		else if (!ft_isalpha(line[i]) && line[i + 1] == P_EASTH
			&& !ft_isalpha(line[i + 2]))
			return (count_player += 1);
		else
			i++;
	}
	return (count_player);
}
