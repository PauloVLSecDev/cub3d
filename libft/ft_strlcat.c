/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:21:28 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/10/23 16:12:46 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		len_src;
	size_t		len_dest;
	size_t		j;

	j = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size == 0)
	{
		return (len_src);
	}
	else if (len_dest >= size)
	{
		return (len_src + size);
	}
	while ((len_dest + j) < (size -1) && (src[j] != '\0'))
	{
		dest[len_dest + j] = src[j];
		j++;
	}
	dest[len_dest + j] = '\0';
	return (len_dest + len_src);
}
