/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cub_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:53 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:54 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	found_str(char *info, char *tofind, t_game *game)
{
	if (tofind[0] == 'N')
	{
		if (!ft_strncmp(info, tofind, 3) && !already_found(game->map->north,
				game))
			return (true);
	}
	else if (tofind[0] == 'S')
	{
		if (!ft_strncmp(info, tofind, 3) && !already_found(game->map->south,
				game))
			return (true);
	}
	else if (tofind[0] == 'W')
	{
		if (!ft_strncmp(info, tofind, 3) && !already_found(game->map->west,
				game))
			return (true);
	}
	else if (tofind[0] == 'E')
	{
		if (!ft_strncmp(info, tofind, 3) && !already_found(game->map->east,
				game))
			return (true);
	}
	return (false);
}

void	found_all_identifier(t_game *game, int *i, char *info)
{
	if ((!game->map->north || !game->map->south || !game->map->west
			|| !game->map->east || !game->map->ceiling || !game->map->floor))
		error("Error\nMissing/Invalid Identifier!", game);
	cut_map(game, *i, info);
}
