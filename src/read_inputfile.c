/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:01:02 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:01:03 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_loop(int fd)
{
	char	*read_line;
	char	*buffer;

	buffer = get_next_line(fd);
	if (!buffer)
		return (NULL);
	read_line = get_next_line(fd);
	if (!read_line)
		return (buffer);
	while (read_line)
	{
		buffer = ft_strjoin(buffer, read_line);
		free(read_line);
		read_line = get_next_line(fd);
	}
	return (buffer);
}

char	*read_inputfile(char *file)
{
	int		fd;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = read_loop(fd);
	close(fd);
	return (buffer);
}
