/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:06:52 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/11/08 13:58:47 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*add_b;

	add_b = (unsigned char *) s;
	while (n > 0)
	{
		*(add_b++) = (unsigned char) c;
		n--;
	}
	return (s);
}
