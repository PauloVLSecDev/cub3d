/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:09:31 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/05 16:07:30 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*cmp_s1;
	unsigned char		*cmp_s2;
	size_t				i;

	cmp_s1 = (unsigned char *)s1;
	cmp_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cmp_s1[i] != '\0' && cmp_s2[i] != '\0' && (i < n - 1))
	{
		if (cmp_s1[i] != cmp_s2[i])
		{
			return (cmp_s1[i] - cmp_s2[i]);
		}
		i++;
	}
	return (cmp_s1[i] - cmp_s2[i]);
}
