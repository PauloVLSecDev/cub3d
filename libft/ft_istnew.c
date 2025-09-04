/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:36:23 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/04 13:37:38 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_istnew(void *content)
{
	t_list	*search;

	search = (t_list *)malloc(sizeof(t_list));
	if (!search)
		return (NULL);
	search->content = content;
	search->next = NULL;
	return (search);
}
