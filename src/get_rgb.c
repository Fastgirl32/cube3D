/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:29 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:30 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**process_rgb(char *buffer, t_game *game)
{
	char	*temp;
	char	**array;
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (buffer[i])
	{
		k++;
		i++;
	}
	temp = ft_calloc(k + 1, sizeof(char));
	if (!temp)
		error("Error\nMalloc failed!\n", game);
	i = 0;
	k = 0;
	while (buffer[k])
	{
		temp[i] = buffer[k++];
		i++;
	}
	array = ft_split(temp, ',');
	free(temp);
	return (array);
}

char	**get_rgb(char *info, int *i, char **plane_position, t_game *game)
{
	char	*buffer;
	char	**array;

	if (plane_position != NULL)
		error("Error\nInvalid config in inputfile\n", game);
	buffer = get_path2(info, i, game);
	if (!buffer)
		error("Error\nColor information missing!\n", game);
	array = process_rgb(buffer, game);
	if (!array)
		error("Error\nMalloc failed!\n", game);
	free(buffer);
	return (array);
}
