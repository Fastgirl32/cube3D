/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:56 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:57 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_index_of_char(char *str, char tofind)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (-1);
	while (str && str[i])
	{
		if (str[i] == tofind)
			return (i);
		i++;
	}
	if (tofind == '\0')
		return (i);
	return (-1);
}

char	*get_path2(char *info, int *i, t_game *game)
{
	char	*path;
	int		j;
	int		k;

	j = 0;
	k = get_index_of_char(&info[j], '\n');
	while (info[j] && j < k && info[j] != '\n' && (info[j] == ' '
			|| info[j] == '\t'))
		j++;
	if (k == -1 || k == 0 || info[j] == '\n')
		return (NULL);
	*i += k + 2;
	k--;
	while (info[k] && info[k] != '\n' && (info[k] == ' ' || info[k] == '\t'))
		k--;
	path = ft_substr(info, j, k - j + 1);
	if (path == NULL)
		error("Error\nMalloc failed in get_path\n", game);
	return (path);
}

char	*get_path(char *info, int *i, t_game *game)
{
	char	*path;
	int		j;
	int		k;

	j = 0;
	k = get_index_of_char(&info[j], '\n');
	while (info[j] && j < k && info[j] != '\n' && (info[j] == ' '
			|| info[j] == '\t'))
		j++;
	if (k == -1 || k == 0 || info[j] == '\n')
		return (NULL);
	*i += k + 3;
	k--;
	while (info[k] && info[k] != '\n' && (info[k] == ' ' || info[k] == '\t'))
		k--;
	path = ft_substr(info, j, k - j + 1);
	if (path == NULL)
		error("Error\nMalloc failed in get_path\n", game);
	return (path);
}

bool	already_found(char *path, t_game *game)
{
	if (path != NULL)
		error("Error\nInvalid config in inputfile\n", game);
	return (false);
}

void	process_cub(t_game *game, char *info, int *i)
{
	while (info[*i] && !(game->map->north && game->map->south && game->map->west
			&& game->map->east && game->map->ceiling && game->map->floor))
	{
		if (found_str(&info[*i], "NO ", game))
			game->map->north = get_path(&info[*i + 3], i, game);
		else if (found_str(&info[*i], "SO ", game))
			game->map->south = get_path(&info[*i + 3], i, game);
		else if (found_str(&info[*i], "WE ", game))
			game->map->west = get_path(&info[*i + 3], i, game);
		else if (found_str(&info[*i], "EA ", game))
			game->map->east = get_path(&info[*i + 3], i, game);
		else if (!ft_strncmp(&info[*i], "C ", 2))
			game->map->ceiling = get_rgb(&info[*i + 2], i, game->map->ceiling,
					game);
		else if (!ft_strncmp(&info[*i], "F ", 2))
			game->map->floor = get_rgb(&info[*i + 2], i, game->map->floor,
					game);
		else if (info[*i] != '\n')
			error("Error\nStray Characters detected!\n", game);
		(*i)++;
	}
	found_all_identifier(game, i, info);
}
