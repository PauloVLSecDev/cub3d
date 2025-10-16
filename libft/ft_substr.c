/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:13:19 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/16 20:10:20 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_s;
	size_t	index;

	index = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (index < len)
		dest[index++] = s[start++];
	dest[index] = '\0';
	return (dest);
}
