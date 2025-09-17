/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:10:23 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/09/17 20:21:04 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define HEIGHT 1080
# define WIDTH 1920

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keycaps.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_image
{
	char	**matriz;
	void	*img;
	char	*addr;

}			t_image;
 
typedef struct s_parse_map
{
	int num_lines;
	int	wall;
	int empyt;
	char *path_texture;
	int	rgb[3]; 
	char **map;		
	
} 			t_parse_map;

int			extencion_map(char *filename);
int			num_player(char *line);
t_parse_map			*stogere_map(int map);

#endif
