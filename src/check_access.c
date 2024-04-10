/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:01 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:02 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_format(char *xpm, t_game *game)
{
	size_t	i;

	i = ft_strlen(xpm);
	if (i < 5 || !(xpm[i - 4] == '.' && xpm[i - 3] == 'x' && xpm[i - 2] == 'p'
			&& xpm[i - 1] == 'm'))
		error("Error\nTextures/wrong fileformat", game);
}

void	check_access(t_game *game)
{
	check_format(game->map->north, game);
	check_format(game->map->east, game);
	check_format(game->map->south, game);
	check_format(game->map->west, game);
	if (access(game->map->north, R_OK) == -1 || access(game->map->south,
			R_OK) == -1 || access(game->map->west, R_OK) == -1
		|| access(game->map->east, R_OK) == -1)
		error("Error\nMissing Textures/Missing Permissions\n", game);
}
