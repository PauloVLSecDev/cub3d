/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:10:23 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/09/11 17:06:22 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H 

//macros 

#define HEIGHT 1080
#define WIDTH 1920
#define PLAYER_CHAR "NSWE"

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "keycaps.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_image
{
	char **matriz; 
	void	*img;
	char	*addr;

}	t_image;

#endif
