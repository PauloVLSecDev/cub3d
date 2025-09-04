/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:50:49 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/10/22 14:52:33 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*copy;
	unsigned char	*source;

	source = (unsigned char *) src;
	copy = (unsigned char *) dest;
	i = 0;
	if (source == (void *)0 && dest == (void *)0)
	{
		return (NULL);
	}
	while (i < n)
	{
		copy[i] = source[i];
		i++;
	}
	return (copy);
}
