/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:48:53 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/11/01 19:33:19 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	size_trim;
	size_t	end;
	size_t	start;

	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	size_trim = end - start;
	dest = (char *)malloc((size_trim + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + start, size_trim + 1);
	return (dest);
}
