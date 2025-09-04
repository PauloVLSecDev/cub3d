/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:41:25 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/04 13:50:17 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
/*
int	main(void)
{
	t_list *lista;
	t_list *zero;
	t_list *um;
	zero = (t_list *)malloc(sizeof(t_list));
	um = (t_list *)malloc(sizeof(t_list));
	lista = (t_list *)malloc(sizeof(t_list));
	lista->next = zero;
	zero->next = um;
	int	size = ft_lstsize(lista);
	printf("\nquantidade de nos, %d\n", size);
}
*/
