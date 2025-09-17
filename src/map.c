/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:23:55 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:49:42 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		if (!ft_isalpha(line[i]) && line[i + 1] == P_SOUTH
				&& !ft_isalpha(line[i + 2]))
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






