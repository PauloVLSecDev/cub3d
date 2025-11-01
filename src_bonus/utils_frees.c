/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_frees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:43:35 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/23 19:48:18 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	close_all(void)
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

void	valid_first_line(t_parse_map *data, char *first_line,
		t_list **map_lines)
{
	little_validade(data, first_line);
	ft_lsadd_back(map_lines, create_node(first_line));
	free(first_line);
}
