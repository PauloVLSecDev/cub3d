/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:34:54 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/10/29 14:26:48 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*types1;
	unsigned char	*types2;
	size_t			i;

	i = 0;
	types1 = (unsigned char *)s1;
	types2 = (unsigned char *)s2;
	while (i < n)
	{
		if (types1[i] != types2[i])
			return (types1[i] - types2[i]);
		i++;
	}
	return (0);
}
