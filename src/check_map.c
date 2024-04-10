/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:07 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:08 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_walls(char **map)
{
	int	i;
	int	k;

	i = -1;
	while (map[++i])
	{
		k = -1;
		while (map[i][++k])
		{
			if (map[i][k] == '0' || map[i][k] == 'E' || map[i][k] == 'S'
				|| map[i][k] == 'W' || map[i][k] == 'N')
			{
				if ((map[i + 1][k] && map[i + 1][k] == ' ') || (map[i - 1][k]
						&& map[i - 1][k] == ' ') || (map[i][k + 1] && map[i][k
						+ 1] == ' ') || (map[i][k - 1] && map[i][k - 1] == ' '))
					return (false);
				if (!map[i + 1][k] || !map[i - 1][k] || !map[i][k + 1]
					|| !map[i][k - 1])
					return (false);
			}
		}
	}
	return (true);
}

bool	check_letter(t_game *game, int height, int width)
{
	if (game->map->map[height][width] == 'N'
		|| game->map->map[height][width] == 'S'
		|| game->map->map[height][width] == 'W'
		|| game->map->map[height][width] == 'E')
		return (true);
	return (false);
}

bool	check_contain(t_game *game)
{
	int	height;
	int	width;
	int	i;

	i = 0;
	height = -1;
	while (game->map->map[++height] != NULL)
	{
		width = 0;
		while (game->map->map[height][width] != '\0')
		{
			if (game->map->map[height][width] == ' ')
				;
			else if (game->map->map[height][width] == '0')
				;
			else if (game->map->map[height][width] == '1')
				;
			else if (i == 0 && (check_letter(game, height, width)))
				i = 1;
			else
				return (false);
			width++;
		}
	}
	return (true);
}

bool	check_border(t_game *game)
{
	int	k;

	k = 0;
	while (game->map->map[(int)game->height - 1][k])
	{
		if ((game->map->map[(int)game->height - 1][k] != '1'
			&& game->map->map[(int)game->height - 1][k] != ' '
			&& game->map->map[(int)game->height - 1][k] != '\n'))
			return (false);
		k++;
	}
	k = 0;
	while (game->map->map[0][k])
	{
		if ((game->map->map[0][k] != '1' && game->map->map[0][k] != ' '
				&& game->map->map[0][k] != '\n'))
			return (false);
		k++;
	}
	return (true);
}

bool	check_map(t_game *game)
{
	if (check_border(game) && check_contain(game)
		&& check_walls(game->map->map))
		return (true);
	return (false);
}
