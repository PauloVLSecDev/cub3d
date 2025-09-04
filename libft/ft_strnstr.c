/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:43:31 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/10/28 17:02:09 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		len_little;

	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	j = 0;
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		if (j + len_little > len)
			return (NULL);
		while (little[i] != '\0' && little[i] == big[i + j])
		{
			i++;
		}
		if (little[i] == '\0')
			return ((char *)&big[j]);
		j++;
	}
	return (NULL);
}
