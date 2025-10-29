/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:01:38 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/11/02 18:21:31 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*con;
	unsigned int	num;
	size_t			size_int;

	if (n < 0)
		num = -n;
	else
		num = n;
	size_int = ft_numlen(n);
	con = (char *)malloc(size_int + 1);
	if (!con)
		return (NULL);
	con[size_int] = '\0';
	while (size_int > 0)
	{
		con[size_int - 1] = (num % 10) + '0';
		size_int--;
		num = num / 10;
	}
	if (n < 0)
		con[0] = '-';
	return (con);
}
