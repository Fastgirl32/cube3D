/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:44 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:45 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	input_check(ac, av[1]);
	game = game_start(av[1]);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_width,
			game->screen_height, "cube3d");
	if (!(game->win_ptr))
		error("Error\nFailed to create window\n", game);
	game->img->img = mlx_new_image(game->mlx_ptr, game->screen_width,
			game->screen_height);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->size_line, &game->img->endian);
	set_player_spawn(game);
	open_all_textures(game);
	ray_casting(game);
	mlx_hook(game->win_ptr, 3, 1L << 1, &key_input, game);
	mlx_hook(game->win_ptr, 17, 0, &close_window, game);
	mlx_loop(game->mlx_ptr);
	free_all(game);
}
