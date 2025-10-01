/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:06 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/01 17:36:43 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int invalid_rgb(char **colors);

int valid_line(char *line, t_parse_map **data)
{
	while (*line)
	{
		while (*line == '\t' || *line == ' ') 
				line++;
		get_colors_F(line, data);
		get_colors_C(line, data);
		ft_iscompass_rose(line, data);
		if (line_is_empty(line))
				return (0);
		line++;
	}
	return (1);
}

void	get_colors_F(char *line, t_parse_map **data)
{
	char **colors;

	colors = NULL;
	if (ft_strncmp(line, "F", 1) == 0)
	{
		colors = ft_split(line, ',');
		if (ft_atoi(colors[0]) >= 0 && ft_atoi(colors[0]) <= 255) 
			(*data)->F_rgb[0] = ft_atoi(colors[0]);
		else
			(*data)->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[1]) >= 0 && ft_atoi(colors[1]) <= 255)
			(*data)->F_rgb[1] = ft_atoi(colors[1]);
		else
			(*data)->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[2]) >= 0 && ft_atoi(colors[2]) <= 255)
			(*data)->F_rgb[2] = ft_atoi(colors[2]);
		else
			(*data)->error_rgb = invalid_rgb(colors);
	}
}

void	get_colors_C(char *line, t_parse_map **data)
{
	char **colors;

	colors = NULL;

	if (ft_strncmp(line, "C", 1) == 0)
	{
		colors = ft_split(line, ',');
		if (ft_atoi(colors[0]) >= 0 && ft_atoi(colors[0]) <= 255) 
			(*data)->C_rgb[0] = ft_atoi(colors[0]);
		else
			(*data)->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[1]) >= 0 && ft_atoi(colors[1]) <= 255)
			(*data)->C_rgb[1] = ft_atoi(colors[1]);
		else
			(*data)->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[2]) >= 0 && ft_atoi(colors[2]) <= 255)
			(*data)->C_rgb[2] = ft_atoi(colors[2]);
		else
			(*data)->error_rgb = invalid_rgb(colors);
	}
	else 
		(*data)->error_rgb = invalid_rgb(colors);
}

static int invalid_rgb(char **colors)
{
	if (colors != NULL)
	{
		free_array(colors);
		printf("invalid color");
		return (1);
	}
	return (1);
}

void	ft_iscompass_rose(char *line, t_parse_map **data)
{
	(*data)->W_texture = 0;
	if (ft_strncmp(line, "SO", 2) == 0 && (*data)->W_texture != 1)
		(*data)->Texture_SO = ft_split(line, ' ');
	else if (ft_strncmp(line, "NO", 2) == 0 && (*data)->W_texture != 1)
		(*data)->Texture_NO = ft_split(line, ' ');
	else if (ft_strncmp(line, "WE", 2) == 0 && (*data)->W_texture != 1) 
		(*data)->Texture_WE = ft_split(line, ' ');
	else 	if (ft_strncmp(line, "EA", 2) == 0 && (*data)->W_texture != 1)
		(*data)->Texture_EA = ft_split(line, ' ');
	else 
		(*data)->W_texture = 1;
}

