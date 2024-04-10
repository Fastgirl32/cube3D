/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:50 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:51 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	open_texture(t_game *game, char *path)
{
	t_texture	ret;

	ret.width = 64;
	ret.height = 64;
	ret.img = mlx_xpm_file_to_image(game->mlx_ptr, path, &ret.width,
			&ret.height);
	if (!ret.img)
		error("Error\nXPM file to image failed!\n", game);
	if (ret.width != game->textwidth || ret.height != game->textheight)
		error("Error\nTexturesize not supported!\n", game);
	ret.path = path;
	ret.addr.img = mlx_get_data_addr(ret.img, &ret.addr.bpp, &ret.addr.sizeline,
			&ret.addr.endian);
	return (ret);
}

void	open_all_textures(t_game *game)
{
	game->e = open_texture(game, game->map->east);
	game->w = open_texture(game, game->map->south);
	game->n = open_texture(game, game->map->west);
	game->s = open_texture(game, game->map->north);
}
