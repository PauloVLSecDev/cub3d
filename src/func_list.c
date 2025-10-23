/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:42:35 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/10/21 18:03:40 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_list	*create_node(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = ft_strdup(content);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	ft_lsadd_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	free_struct(t_parse_map *data, char *menssage)
{
	t_list	*tmp;
	t_list	*next;

	if (!data)
		return ;
	tmp = data->list;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
		tmp = next;
	}
	data->list = NULL;
	if (data->map)
		free_array(data->map);
	printf("%s", menssage);
}

void	free_list(t_list **head)
{
	t_list	*tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		if ((*head)->line)
			free((*head)->line);
		free(*head);
		*head = tmp;
	}
}

void	free_textures(t_parse_map *data)
{
	if (!data)
		return ;
	if (data->texture_no)
	{
		free(data->texture_no);
		data->texture_no = NULL;
	}	
	if (data->texture_so)
	{
		free(data->texture_so);
		data->texture_so = NULL;
	}
	if (data->texture_we)
	{
		free(data->texture_we);
		data->texture_we = NULL;
	}
	if (data->texture_ea)
	{
		free(data->texture_ea);
		data->texture_ea = NULL;
	}
}
