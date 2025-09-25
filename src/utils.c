/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:06 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/09/18 17:50:32 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int invalid_rgb(char **colors);

int valid_line(char *line, t_parse_map **data)
{
	int flag;

	while (*line && *line != "\n")
	{
		while (*line == '\t' || *line == ' ') 
				line++;
		get_colors_F(line, &data):
		get_colors_C(line, &data):
		ft_iscompass_rose(line, data):
		if (ft_isdigit(line);
				return (1);
		line++;
	}
	return (0);
}

void	get_colors_F(char *line, t_parse_map **data)
{
	char **colors;

	coiors = NULL;
	if (ft_strncmp(line, "F", 1) == 0)
	{
		colors = ft_split(line, ",");
		if (ft_atoi(colors[0]) >= 0 && ft_atoi(colors[0]) <= 255) 
			*(data)->RGB[0] = ft_atoi(colors[0]);
		else
			*(data)->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[1]) >= 0 && ft_atoi(colors[1]) <= 255)
			*(data)->RGB[1] = ft_atoi(colors[1]);
		else
			*(data)->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[2]) >= 0 && ft_atoi(colors[2]) <= 255)
			*(data)->RGB[2] = ft_atoi(colors[2]);
		else
			*(data)->error_rgb = invalid_rgb(colors);
	}
{

void	get_colors_C(char *line, t_parse_map **data)
{
	char **colors;

	coiors = NULL;
	if (ft_strncmp(line, "C", 1) == 0)
	{
		colors = ft_split(line, ",");
		if (ft_atoi(colors[0]) >= 0 && ft_atoi(colors[0]) <= 255) 
			*(data)->RGB[0] = ft_atoi(colors[0]);
		else
			data->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[1]) >= 0 && ft_atoi(colors[1]) <= 255)
			*(data)->RGB[1] = ft_atoi(colors[1]);
		else
			*data->error_rgb = invalid_rgb(colors);
		if (ft_atoi(colors[2]) >= 0 && ft_atoi(colors[2]) <= 255)
			*(data)->RGB[2] = ft_atoi(colors[2]);
		else
			*(data)->error_rgb = invalid_rgb(colors);
	}
	else 
		*(data)->error_rgb = invalid_rgb(colors);
{

static int invalid_rgb(char **colors)
{
	if (colors != NULL)
	{
		free_all(colors);
		printf("invalid color");
		return (1);
	}
	return (1);
}

void	ft_iscompass_rose(char *line, t_parse_map **data); 
{
	*data->W_texture = 0;
	if (ft_strncmp(line, "SO", 2) == 0 && *data->W_texture != 1)
		*(data)->Textura_SO = ft_split(line, " ");
	else if (ft_strcmp(line, "NO", 2) == 0 && *data->W_texture != 1)
		*(data)->Textura_NO = ft_split(line, " ");
	else if (ft_strncmp(line, "WE", 2) == 0 && *data->W_texture != 1) 
		*(data)->Textura_WE = ft_split(line, " ");
	else 	if (ft_strncmp(line, "EA", 2) == 0 && *data->W_texture != 1)
		*(data)->Textura_EA = ft_split(line, " ");
	else 
		*data->W_texture = 1;
}

