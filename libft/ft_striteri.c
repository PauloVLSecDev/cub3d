/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:50:50 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/11/02 20:19:35 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		index;	
	unsigned int		size_s;	

	size_s = ft_strlen(s);
	index = 0;
	while (index < size_s)
	{
		f(index, &s[index]);
		index++;
	}
}
