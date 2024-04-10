/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:47 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:48 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_turn_left(t_game *game)
{
	game->ray->olddir_x = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x * cos(-0.05) - game->ray->dir_y
		* sin(-0.05);
	game->ray->dir_y = game->ray->olddir_x * sin(-0.05) + game->ray->dir_y
		* cos(-0.05);
	game->ray->oldplane_x = game->ray->plane_x;
	game->ray->plane_x = game->ray->plane_x * cos(-0.05) - game->ray->plane_y
		* sin(-0.05);
	game->ray->plane_y = game->ray->oldplane_x * sin(-0.05) + game->ray->plane_y
		* cos(-0.05);
	ray_casting(game);
}

void	player_turn_right(t_game *game)
{
	game->ray->olddir_x = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x * cos(0.05) - game->ray->dir_y
		* sin(0.05);
	game->ray->dir_y = game->ray->olddir_x * sin(0.05) + game->ray->dir_y
		* cos(0.05);
	game->ray->oldplane_x = game->ray->plane_x;
	game->ray->plane_x = game->ray->plane_x * cos(0.05) - game->ray->plane_y
		* sin(0.05);
	game->ray->plane_y = game->ray->oldplane_x * sin(0.05) + game->ray->plane_y
		* cos(0.05);
	ray_casting(game);
}

void	player_move_backward(t_game *game)
{
	double	movespeed;

	movespeed = 0.2;
	if (game->map->map[(int)game->ray->pos_y][(int)(game->ray->pos_x
		- game->ray->dir_x * movespeed)] != '1')
		game->player->pos_x -= game->ray->dir_x * movespeed;
	if (game->map->map[(int)(game->ray->pos_y - game->ray->dir_y
			* 0.2)][(int)game->ray->pos_x] != '1')
		game->player->pos_y -= game->ray->dir_y * movespeed;
	ray_casting(game);
}

void	player_move_forward(t_game *game)
{
	double	movespeed;

	movespeed = 0.2;
	if (game->map->map[(int)(game->ray->pos_y + game->ray->dir_y
			* movespeed)][(int)game->ray->pos_x] != '1')
		game->player->pos_y += game->ray->dir_y * movespeed;
	if (game->map->map[(int)game->ray->pos_y][(int)(game->ray->pos_x
		+ game->ray->dir_x * movespeed)] != '1')
		game->player->pos_x += game->ray->dir_x * movespeed;
	ray_casting(game);
}

void	player_move_right(t_game *game)
{
	double	movespeed;

	movespeed = 0.2;
	if (game->map->map[(int)(game->ray->pos_y + game->ray->dir_x
			* movespeed)][(int)game->ray->pos_x] != '1')
		game->player->pos_y += game->ray->dir_x * movespeed;
	if (game->map->map[(int)game->ray->pos_y][(int)(game->ray->pos_x
		- game->ray->dir_y * movespeed)] != '1')
		game->player->pos_x -= game->ray->dir_y * movespeed;
	ray_casting(game);
}
