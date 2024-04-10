/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:58:21 by phnowak           #+#    #+#             */
/*   Updated: 2023/09/21 15:50:51 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// For Comments, check get_next_line.c it's the same just without 2D arrays
char	*read_buffer(int fd, char *read_line)
{
	int		read_chars;
	char	*read_buffer;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (read_buffer == NULL)
		return (NULL);
	read_chars = 1;
	while (!gnl_strchr(read_line, '\n') && read_chars != 0)
	{
		read_chars = read(fd, read_buffer, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(read_buffer);
			free(read_line);
			return (NULL);
		}
		read_buffer[read_chars] = '\0';
		read_line = gnl_strjoin(read_line, read_buffer);
	}
	free(read_buffer);
	return (read_line);
}

char	*read_line_until_nl(char *read_line)
{
	int		len;
	char	*line;

	len = 0;
	if (!read_line[len])
		return (NULL);
	while (read_line[len] && read_line[len] != '\n')
		len++;
	line = (char *)malloc(len + 2);
	if (line == NULL)
		return (NULL);
	gnl_strlcpy(line, read_line, len + 2);
	return (line);
}

char	*deline_from_read_line(char *read_line)
{
	char	*new_string;
	char	*substring;

	if (read_line[0] == '\0')
	{
		free(read_line);
		return (NULL);
	}
	new_string = gnl_strchr(read_line, '\n');
	if (new_string == NULL)
	{
		free(read_line);
		return (NULL);
	}
	else
	{
		substring = gnl_substr(new_string, 1, gnl_strlen(new_string));
		free(read_line);
		return (substring);
	}
}

char	*get_next_line(int fd)
{
	static char	*read_line[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line[fd] = read_buffer(fd, read_line[fd]);
	if (read_line[fd] == NULL)
		return (NULL);
	line = read_line_until_nl(read_line[fd]);
	read_line[fd] = deline_from_read_line(read_line[fd]);
	return (line);
}
