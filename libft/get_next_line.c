/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/17 15:49:56 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	char	*new_line;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	new_line = ft_strchr(*buffer, '\n');
	if (new_line)
	{
		line = ft_substr(*buffer, 0, new_line - *buffer + 1);
		temp = ft_strdup(new_line + 1);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static char	*read_file(int fd, char **buffer)
{
	char		*line;
	int			size_read;
	char		*temp;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (1)
	{
		size_read = read(fd, line, BUFFER_SIZE);
		if (size_read == -1)
			return (free(*buffer), free(line),
				*buffer = NULL, NULL);
		if (size_read == 0)
			break ;
		line[size_read] = '\0';
		temp = ft_strjoin(*buffer, line);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(line);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	read_file(fd, &buffer);
	new_line = extract_line(&buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (new_line);
}
