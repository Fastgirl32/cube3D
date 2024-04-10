/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_spawn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:01:04 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:01:05 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_spawn(t_game *game)
{
	game->ray->dir_x = 0;
	game->ray->dir_y = 0;
	game->ray->plane_x = 0;
	game->ray->plane_y = 0;
	if (game->player->spawn_dir == 'N')
	{
		game->ray->dir_y = -1;
		game->ray->plane_x = 0.66;
	}
	else if (game->player->spawn_dir == 'S')
	{
		game->ray->dir_y = 1;
		game->ray->plane_x = -0.66;
	}
	else if (game->player->spawn_dir == 'E')
	{
		game->ray->dir_x = 1;
		game->ray->plane_y = 0.66;
	}
	else if (game->player->spawn_dir == 'W')
	{
		game->ray->dir_x = -1;
		game->ray->plane_y = -0.66;
	}
}
