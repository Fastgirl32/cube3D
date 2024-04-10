/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground_and_sky.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:32 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:33 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	make_sky(t_game *game)
{
	t_index	index;
	int		color;

	index.i = 0;
	color = set_rgb(ft_atoi(game->map->ceiling[0]),
			ft_atoi(game->map->ceiling[1]), ft_atoi(game->map->ceiling[2]));
	while (index.i < game->screen_height / 2)
	{
		index.j = 0;
		while (index.j < game->screen_width)
		{
			img_pxl_put(game, index.j, index.i, color);
			index.j++;
		}
		index.i++;
	}
}

void	make_floor(t_game *game)
{
	t_index	index;
	int		color;

	index.i = 0;
	color = set_rgb(ft_atoi(game->map->floor[0]), ft_atoi(game->map->floor[1]),
			ft_atoi(game->map->floor[2]));
	index.i = game->screen_height / 2;
	while (index.i < game->screen_height)
	{
		index.j = 0;
		while (index.j < game->screen_width)
		{
			img_pxl_put(game, index.j, index.i, color);
			index.j++;
		}
		index.i++;
	}
}

void	create_bg(t_game *game)
{
	make_sky(game);
	make_floor(game);
}
