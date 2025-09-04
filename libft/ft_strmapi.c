/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:37:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/11/02 19:44:03 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	len_s;
	unsigned int	index;

	index = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	new_string = (char *)ft_calloc((len_s + 1), sizeof(char));
	if (!new_string)
		return (NULL);
	while (index < len_s)
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
