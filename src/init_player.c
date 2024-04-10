/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:35 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:36 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	helper_function(t_game *game, int k)
{
	if (k != 1)
		error("Error\nSpawnpoint missing!\n", game);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;
	int	k;

	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error("Error\nMalloc failed!\n", game);
	i = -1;
	k = 0;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (game->map->map[i][j] == 'N' || game->map->map[i][j] == 'E'
				|| game->map->map[i][j] == 'S' || game->map->map[i][j] == 'W')
			{
				game->player->pos_y = i;
				game->player->pos_x = j;
				game->player->spawn_dir = game->map->map[i][j];
				k++;
			}
		}
	}
	helper_function(game, k);
}
