/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:06 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/23 20:22:45 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	get_texture(char **tokens, t_parse_map *data);

int	all_configs_loaded(t_parse_map *data)
{
	if (data->texture_no && data->texture_so && data->texture_we
		&& data->texture_ea && data->f_rgb[0] != -1 && data->c_rgb[0] != -1)
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
	if (!get_texture(tokens, data))
	{
		free_textures(data);
		free_array(tokens);
		free_struct(data, "invalid texture\n");
		close_all();
		free(line);
		exit(1);
	}
	free_array(tokens);
}

void	parse_colors_c(char *rgb_str, t_parse_map *data)
{
	char	**rgb_val;
	int		i;

	rgb_val = ft_split(rgb_str, ',');
	if (!rgb_val || !rgb_val[0] || !rgb_val[1] || !rgb_val[2] || rgb_val[3])
	{
		printf("Error: Color format RGB invalid.\n");
		if (rgb_val)
			free_array(rgb_val);
		return ;
	}
	i = 0;
	while (i < 3)
	{
		data->c_rgb[i] = ft_atoi(rgb_val[i]);
		if (data->c_rgb[i] < 0 || data->c_rgb[i] > 255)
		{
			printf("Error: color value valid is 0-255.\n");
			data->c_rgb[0] = -1;
			break ;
		}
		i++;
	}
	free_array(rgb_val);
}

void	parse_colors_f(char *rgb_str, t_parse_map *data)
{
	char	**rgb_val;
	int		i;

	rgb_val = ft_split(rgb_str, ',');
	if (!rgb_val || !rgb_val[0] || !rgb_val[1] || !rgb_val[2] || rgb_val[3])
	{
		printf("Error: Color format RGB invalid.\n");
		if (rgb_val)
			free_array(rgb_val);
		return ;
	}
	i = 0;
	while (i < 3)
	{
		data->f_rgb[i] = ft_atoi(rgb_val[i]);
		if (data->f_rgb[i] < 0 || data->f_rgb[i] > 255)
		{
			printf("Error: color value valid is 0-255.\n");
			data->f_rgb[0] = -1;
			break ;
		}
		i++;
	}
	free_array(rgb_val);
}

static int	get_texture(char **tokens, t_parse_map *data)
{
	if (ft_strncmp(tokens[0], "NO", 3) == 0 && !data->texture_no)
		data->texture_no = ft_strtrim(tokens[1], "\n");
	else if (ft_strncmp(tokens[0], "SO", 3) == 0 && !data->texture_so)
		data->texture_so = ft_strtrim(tokens[1], "\n");
	else if (ft_strncmp(tokens[0], "WE", 3) == 0 && !data->texture_we)
		data->texture_we = ft_strtrim(tokens[1], "\n");
	else if (ft_strncmp(tokens[0], "EA", 3) == 0 && !data->texture_ea)
		data->texture_ea = ft_strtrim(tokens[1], "\n");
	else if (ft_strncmp(tokens[0], "F", 2) == 0 && data->f_rgb[0] == -1)
		parse_colors_f(tokens[1], data);
	else if (ft_strncmp(tokens[0], "C", 2) == 0 && data->c_rgb[0] == -1)
		parse_colors_c(tokens[1], data);
	else
	{
		if (!all_configs_loaded(data))
		{
			return (0);
		}
	}
	return (1);
}
