/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:10:23 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/01 17:21:04 by pvitor-l         ###   ########.fr       */
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
# include <stdbool.h>
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
	char **Texture_SO;
	char **Texture_NO;
	char **Texture_WE;
	char **Texture_EA;
	int	W_texture;
	int	F_rgb[3]; 
	int	C_rgb[3]; 
	int valid_colors;
	int error_rgb;
	char **map;		
	
} 			t_parse_map;

int			extencion_map(char *filename);
int			num_player(char *line);
bool 		line_is_empty(char *line);
int			valid_line(char *line, t_parse_map **data);
void	get_colors_F(char *line, t_parse_map **data);
void	get_colors_C(char *line, t_parse_map **data);
void	ft_iscompass_rose(char *line, t_parse_map **data); 
t_parse_map			*stogere_map(int map);

#endif

