/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:04 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:05 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_range(char **color, t_game *game)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	while (color[i])
	{
		str = ft_strtrim(color[i], " ");
		if (!str)
			error("Error\nMalloc failed!\n", game);
		free(color[i]);
		color[i] = str;
		k = 0;
		while (color[i][k])
		{
			if (!ft_isdigit(color[i][k]))
				error("Error\nColor out of range!\n", game);
			k++;
		}
		i++;
	}
	if (!(ft_atoi(color[0]) >= 0 && ft_atoi(color[0]) <= 255
			&& ft_atoi(color[1]) >= 0 && ft_atoi(color[1]) <= 255
			&& ft_atoi(color[2]) >= 0 && ft_atoi(color[2]) <= 255))
		error("Error\nRGB values invalid!\n", game);
}

void	check_color(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->ceiling[i])
		i++;
	if (i != 3)
		error("Error\nWrong number of RGB values!\n", game);
	i = 0;
	while (game->map->floor[i])
		i++;
	if (i != 3)
		error("Error\nWrong number of RGB values!\n", game);
	check_range(game->map->ceiling, game);
	check_range(game->map->floor, game);
}
