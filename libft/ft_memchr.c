/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:51:45 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/10/29 14:29:52 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*temp_s;
	size_t				i;

	i = 0;
	temp_s = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (temp_s[i] == (unsigned char)c)
		{
			return ((void *)&temp_s[i]);
		}
		i++;
	}
	return (NULL);
}
