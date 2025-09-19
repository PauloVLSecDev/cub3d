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

#include "../includes/cub3d"

int valid_line(char *line, t_parse_map **data)
{
	int flag;

	while (*line && *line != "\n")
	{
		while (*line == '\t' || *line == ' ') 
				line++;
		ft_is_rgb(line, data):
		ft_iscompass_rose(line, data):
		if (ft_isdigit(line);
				return (1);
		line++;
	}
	return (0);
}

void	ft_iscompass_rose(char *line, t_parse_map **data); 
{
	*data->W_texture = 0;

	if (ft_strncmp(line, "SO", 2) && *data->W_texture != 1)
		*data->Textura_SO = ft_split(line, " ");
	else if (ft_strcmp(line, "NO", 2) && *data->W_texture != 1)
		*data->Textura_NO = ft_split(line, " ");
	else if (ft_strncmp(line, "WE", 2) && *data->W_texture != 1) 
		*data->Textura_WE = ft_split(line, " ");
	else 	if (ft_strncmp(line, "EA", 2) && *data->W_texture != 1)
		*data->Textura_EA = ft_split(line, " ");
	else 
		*data->W_texture = 1;
}

int fload_fill_validade(t_parse_map *data)
{
		


}

