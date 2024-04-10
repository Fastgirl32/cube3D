/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:26 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:27 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_structs2(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
		error("Error\nMalloc failed in init_game\n", game);
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (game->ray == NULL)
		error("Error\nMalloc failed in init_game\n", game);
	game->img = ft_calloc(1, sizeof(t_img));
	if (game->img == NULL)
		error("Error\nMalloc failed in init_game\n", game);
}

void	init_structs(t_game *game, char *input)
{
	init_structs2(game);
	game->img->addr = NULL;
	game->map->info = read_inputfile(input);
	if (game->map->info == NULL)
		error("Error\nFail to open inputfile!\n", game);
	split_info(game);
	init_player(game);
}

t_game	*game_start(char *input)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		error("Error\nMalloc failed in init_game\n", game);
	init_structs(game, input);
	game->mlx_ptr = mlx_init();
	if (!(game->mlx_ptr))
		error("Error\nFailed to initialize mlx\n", game);
	return (game);
}
