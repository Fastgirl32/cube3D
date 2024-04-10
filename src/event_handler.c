/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:18 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:19 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_left(t_game *game)
{
	double	movespeed;

	movespeed = 0.2;
	if (game->map->map[(int)(game->ray->pos_y - game->ray->dir_x
			* movespeed)][(int)game->ray->pos_x] != '1')
		game->player->pos_y -= game->ray->dir_x * movespeed;
	if (game->map->map[(int)game->ray->pos_y][(int)(game->ray->pos_x
		+ game->ray->dir_y * movespeed)] != '1')
		game->player->pos_x += game->ray->dir_y * movespeed;
	ray_casting(game);
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

int	key_input(int key, t_game *game)
{
	if (key == 0xff1b)
		mlx_loop_end(game->mlx_ptr);
	if (key == 119 || key == 0x0057 || key == 0x0077)
		player_move_forward(game);
	if (key == 115 || key == 0x0053 || key == 0x0073)
		player_move_backward(game);
	if (key == 100 || key == 0x0044 || key == 0x006)
		player_move_right(game);
	if (key == 97 || key == 0x0041 || key == 0x0061)
		player_move_left(game);
	if (key == 0xff53)
		player_turn_right(game);
	if (key == 0xff51)
		player_turn_left(game);
	return (0);
}
